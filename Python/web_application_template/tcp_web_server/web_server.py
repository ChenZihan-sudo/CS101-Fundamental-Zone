from socket import *
import os
import sys

HTML_FILE_PATH = "./hello_world.html"
NO_FOUND_PATH = "./404.html"


# Get html file content
def getContent(path):
    fd = os.open(path, os.O_RDONLY)
    htmlContent = ""
    while True:
        content = os.read(fd, 100)
        if content == b"":
            break
        htmlContent += content.decode(encoding="utf-8")
    return htmlContent


# Reference: https://docs.python.org/3/howto/sockets.html
# Reference: https://www.codementor.io/@joaojonesventura/building-a-basic-http-server-from-scratch-in-python-1cedkg0842

# UDP: SOCK_DGRAM
# TCP: SOCK_STREAM
serverSocket = socket(AF_INET, SOCK_STREAM)
# set socket reuse
serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
# bind(()) give a tuple()
# s.bind(('', 80)) specifies that the socket is
# reachable by any address the machine happens to have.
serverSocket.bind(("", 80))
# Finally, the argument to listen tells the socket library
# that we want it to queue up as many as 5 connect requests (the normal max)
# before refusing outside connections.
# If the rest of the code is written properly, that should be plenty.
serverSocket.listen()  # UDP not support listen for connections


while True:
    (peerSocket, peerAddrInfo) = serverSocket.accept()
    print("Receive connector:", peerAddrInfo)
    request = peerSocket.recv(1024).decode()
    headers = request.split("\n")
    filename = headers[0].split(" ")[1]

    # for item in headers:
    #     item = item.split("\r")[0]
    #     if item.find("Referer") >= 0:
    #         filename = item.split(":")[2].split("/")[3]
    print("Filename:", filename)

    if filename == "/main.html" or filename == "/":
        print("Success")
        response = "HTTP/1.0 200 OK\n\n"
        response += getContent(HTML_FILE_PATH)
        peerSocket.sendall(response.encode())
        peerSocket.close()
    else:
        print("404 Not Found")
        response = "HTTP/1.0 200 OK\n\n"
        response += getContent(NO_FOUND_PATH)
        peerSocket.sendall(response.encode())
        peerSocket.close()

sys.exit()
