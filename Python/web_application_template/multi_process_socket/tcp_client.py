import sys
import os
import optparse
import signal
from socket import *
import errno


def main(msg, serverName, serverPort):
    print(msg, serverName, serverPort)
    clientSocket = socket(AF_INET, SOCK_STREAM)
    clientSocket.connect((serverName, serverPort))
    clientSocket.sendall(msg.encode())
    print("Wait for receive encrypt data...")
    try:
        (recvMsg, serverAddress) = clientSocket.recvfrom(1024)
        print(f"From {serverAddress} receive encrypt data: {recvMsg.decode()}")
    except:
        raise RuntimeError("Failed to receive from socket")


if __name__ == "__main__":
    PORT_DEFAULT = 16000
    IP_ADDRESS = "127.0.0.1"
    parser = optparse.OptionParser()
    parser.add_option(
        "-m", "--msg", dest="message", type="string", help="Message to encrypt."
    )
    parser.add_option(
        "-i",
        "--host",
        dest="host",
        default=IP_ADDRESS,
        help=f"Hostname or IP address. Default is {IP_ADDRESS}",
    )
    parser.add_option(
        "-p",
        "--port",
        dest="port",
        type="int",
        default=PORT_DEFAULT,
        help=f"Port. Default is {PORT_DEFAULT}",
    )
    (options, args) = parser.parse_args()
    main(options.message, options.host, options.port)
