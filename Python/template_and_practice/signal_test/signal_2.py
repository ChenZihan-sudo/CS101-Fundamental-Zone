# -*- coding: utf-8 -
import signal
import os
import time


def receive_signal(signum, frame):
    print(f"Signal received: {signum} {frame}")


def do_exit(signum, frame):
    print(f"Signal exit received: {signum} {frame}")
    raise SystemExit("Exiting")


signal.signal(signal.SIGUSR1, receive_signal)
signal.signal(signal.SIGUSR2, do_exit)

print(f"PID is {os.getpid()}")

while True:
    print("Waiting")
    time.sleep(3)
