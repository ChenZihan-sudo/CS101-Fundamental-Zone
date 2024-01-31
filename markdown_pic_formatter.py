import os
import re
import optparse
from difflib import SequenceMatcher
from shutil import move


def findAllExtFile(rootPath, extName, depth=0):
    dirList = os.listdir(rootPath)
    for i in range(len(dirList)):
        presentPath = rootPath + "/" + dirList[i]
        pathIsDir = os.path.isdir(presentPath)
        if pathIsDir:
            depth += 1
            allDir = findAllExtFile(presentPath, extName, depth)
            while True:
                try:
                    yield next(allDir)
                except StopIteration:
                    # print("End of get dir")
                    break
        else:
            # print(presentPath, rootPath)
            filenameExtension = presentPath.split("/")[-1:][0].split(".")[-1:][0]
            if filenameExtension == extName:
                yield (rootPath, presentPath)


def longestCommonSequence(str1, str2):
    seqMatcher = SequenceMatcher(None, str1, str2)
    match = seqMatcher.find_longest_match(0, len(str1), 0, len(str2))
    return match


def getRelativePath(fromPath: str, toPath: str) -> str:
    match = longestCommonSequence(fromPath, toPath)
    lastToPath = toPath[match.b + match.size :]
    if lastToPath.startswith("/"):
        lastToPath = lastToPath[1:]
    parentPath = fromPath[match.a : match.size]
    if parentPath[-1] == "/":
        parentPath = parentPath[:-1]
    # print(match, toPath, lastToPath, parentPath)

    relativePath = ""

    cwd = fromPath
    # print(fromPath)
    while cwd != "":
        if cwd == parentPath or cwd == "/":
            relativePath += lastToPath
            break
        subpath = "/" + cwd.split("/")[-1:][0]
        cwd = cwd[: cwd.find(subpath)]
        relativePath += "../"
    return relativePath.rstrip("/")


def localPicPathMigrate(
    markdownParentPath, imageSrcPath, migrateDirPath, deleteOrigin=True
) -> str:
    imageFilename = imageSrcPath.split("/")[-1:][0]
    imageDstPath = migrateDirPath + "/" + imageFilename
    print(f"[Local] Migrate image: [{imageSrcPath}]->[{imageDstPath}]")
    try:
        dstPath = move(imageSrcPath, imageDstPath)
    except OSError:
        print(
            f"Failed to migrate image {imageFilename}. Terminate current step and revert. (X)[{imageSrcPath}]->[{imageDstPath}]"
        )
        return None

    # Get relative path
    relativePath = getRelativePath(markdownParentPath, migrateDirPath)
    # print(relativePath)
    return relativePath + "/" + imageFilename


def markdownImageFormatter(markdownParentPath, markdownPath, imageMigratePath):
    document = open(markdownPath, mode="r")
    lineData = document.readlines()
    document.close()

    # position = 0
    for lineItem in enumerate(lineData):
        isMigrate = False
        # modifiedOuterOffset = []
        # modifiedInnerOffset = []

        def localPathMigrate(match):
            # nonlocal modifiedInnerOffset
            # modifiedInnerOffset.append(match.span())
            imageSrcPath = match.groups()[0]
            relativePath = localPicPathMigrate(
                markdownParentPath, imageSrcPath, imageMigratePath
            )
            if relativePath is None:
                relativePath = imageSrcPath
            return "(" + relativePath + ")"

        def remotePathMigrate(match):
            pass

        def markdownPicFormatRes(match):
            nonlocal isMigrate
            isMigrate = True
            # nonlocal modifiedOuterOffset
            # modifiedOuterOffset.append(match.span())
            picFormatString = match.string[match.span()[0] : match.span()[1]]

            replacedString = re.sub(
                r"\(([^()]*)\)", localPathMigrate, picFormatString, count=0
            )

            return replacedString

        def htmlPicFormatRes(match):
            nonlocal isMigrate
            isMigrate = True
            picFormatString = match.string[match.span()[0] : match.span()[1]]
            replacedString = re.sub(
                r"\(([^()]*)\)", pathMigrate, picFormatString, count=0
            )

            return replacedString

        # handle for markdown grammar
        replacedString = re.sub(r"!\[.*?]\(.*?\)", markdownPicFormatRes, lineItem[1])

        # handle for html grammar
        replacedString = re.sub(
            r"<img.*?src=\"(.*?)\".*?\/>", htmlPicFormatRes, replacedString
        )

        # modifiedOffset = []
        # if len(modifiedOuterOffset) > 0:
        #     for outer in enumerate(modifiedOuterOffset):
        #         inner = modifiedInnerOffset[outer[0]]
        #         modifiedOffset.append((outer[1][0] + inner[0], outer[1][0] + inner[1]))

        if isMigrate is True:
            lineData[lineItem[0]] = replacedString

        # print("!!!!", modifiedOuterOffset, modifiedInnerOffset, modifiedOffset)
        # print("Str before", len(lineItem[1]), " after:", len(replacedString))

    allData = ""
    for lineItem in enumerate(lineData):
        allData += lineItem[1]
    with open(markdownPath, mode="w+", encoding="utf-8") as f:
        f.write(allData)


def main():
    parser = optparse.OptionParser()
    parser.add_option(
        "-p",
        "--path",
        dest="imagePath",
        default="./.pics",
        help="image storage directory path",
    )
    parser.add_option(
        "-C",
        "--createDir",
        action="store_true",
        dest="isCreateDir",
        help="create directory if storage path not exist",
    )
    (options, args) = parser.parse_args()
    print("Option parse: ", options, args)

    imagePath = options.imagePath
    isCreateDir = options.isCreateDir
    isImagePathExist = os.path.isdir(imagePath)

    imageFullPath = os.path.realpath(imagePath)
    workDirectory = os.getcwd()

    if (not isImagePathExist) and (not isCreateDir):
        raise IsADirectoryError(
            "Directory not exist. Use '-C' to create with directory."
        )
    else:
        try:
            os.mkdir(imagePath)
        except FileExistsError:
            pass

    allMarkdown = findAllExtFile(workDirectory, "md")

    markdownParentPath, markdownPath = (
        "/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts",
        "/Users/catcolia/Desktop/ChenZihan/Codes/CS101-Fundamental-Zone/Scripts/test.md",
    )

    markdownImageFormatter(markdownParentPath, markdownPath, imageFullPath)

    # while True:
    #     try:
    #         # next(allMarkdown)
    #         print(next(allMarkdown))
    #     except StopIteration:
    #         # print("End of get dir")
    #         break


if __name__ == "__main__":
    main()
