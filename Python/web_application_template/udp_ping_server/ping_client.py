import random
import sys
import os
import time
from socket import *

serverName = "127.0.0.1"
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1)


def genMsg(times):
    t = time.time()
    return (t, "[--->*]PING " + str(times) + " " + str(t))


loss = 0
averageLantencyNs = 0
SEND_SIZE = 10
for i in range(0, SEND_SIZE):
    (sendTime, message) = genMsg(i)
    clientSocket.sendto(message.encode(), (serverName, serverPort))
    try:
        (recvMsg, serverAddress) = clientSocket.recvfrom(1024)
        recvTime = time.time()
        recvMsgList = recvMsg.decode().split(" ")
        int(recvMsgList[1])
        RTT_time = (recvTime - float(recvMsgList[2])) * 1000 * 1000
        averageLantencyNs += RTT_time
        print(f"Seq: {i}. RTT_time: {round(RTT_time,2)}ns ")
    except timeout:
        print(f"[!] Seq {i} timeout.")
        loss += 1

averageLantencyNs = averageLantencyNs / (SEND_SIZE - loss)
print(
    f"Total send: {SEND_SIZE}, loss: {loss}, lantency: {round(averageLantencyNs,2)}ns"
)
