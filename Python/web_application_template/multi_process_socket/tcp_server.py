import os
import optparse
import signal
import socket
import errno


def childToHandle(peerSocket):
    bytes_data = peerSocket.recv(1024)
    print(f"Data received: {bytes_data.decode()}")
    bytes_data = bytearray(bytes_data)
    for i in range(len(bytes_data)):
        bytes_data[i] += 2
    print(f"Data encrypted: {bytes_data.decode()}")
    peerSocket.sendall(bytes_data)
    print(f"End of all handle.")


def reap_children(signum, frame):
    print("Reap children now.")
    while True:
        try:
            # -1 指任意子进程
            (pid, status) = os.waitpid(-1, os.WNOHANG)
            print(pid, status)
            # os.WNOHANG 操作系统在等待子进程状态变化时不要阻塞父进程
            if pid == 0:
                break
        except:
            break


def serve_forever(host, port):
    signal.signal(signal.SIGCHLD, reap_children)  # terminate signal of its child

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind((host, port))
    sock.listen(5)

    print(f"Listening on port {port}")

    while True:
        try:
            (peerSocket, peerAddr) = sock.accept()
        except IOError as e:
            (code, msg) = e.args
            print(f"Socket IOError occurred. {code}: {msg}")
            if code == errno.EINTR:  # error interrupt
                continue
            else:
                raise RuntimeError("Can't handle that kind of error")

        pid = os.fork()
        if pid == 0:  # child
            # close listening socket
            sock.close()
            childToHandle(peerSocket)
            os._exit(0)
        else:  # parent
            peerSocket.close()


def main():
    PORT_DEFAULT = 16000
    IP_ADDRESS = "127.0.0.1"
    parser = optparse.OptionParser()
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

    print(options, args)
    serve_forever(options.host, options.port)


if __name__ == "__main__":
    main()
