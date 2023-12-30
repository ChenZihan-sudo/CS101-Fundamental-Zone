import os
import optparse


# def parse(options, args):
#     print(options, args)
#     os.listdir()


def main():
    parser = optparse.OptionParser()
    parser.add_option(
        "-p",
        "--path",
        dest="path",
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
    print(options, args)

    imagePath = options.imagePath
    isCreateDir = options.isCreateDir

    isImagePathExist = os.path.isdir(imagePath)
    if (not isImagePathExist) and (not isCreateDir):
        raise IsADirectoryError("Directory not exist")
    
    


if __name__ == "__main__":
    main()
