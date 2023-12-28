import random
import sys
import os
from socket import *

serverSocket = socket(AF_INET, SOCK_DGRAM)

serverSocket.bind(("", 12000))
while True:
    rand = random.randint(0, 10)
    (message, address) = serverSocket.recvfrom(1024)
    print("Receive ping: ", message.decode())
    msgList = message.decode().split(" ")
    message = "[C*<---]PING " + msgList[1] + " " + msgList[2]
    if rand < 4:
        continue
    serverSocket.sendto(message.encode(), address)


sys.exit()
