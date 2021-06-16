import subprocess
import os
import unittest
import time, requests
import websocket
import serial
import time
import timeout_decorator

LOCAL_TIMEOUT = 3
PORT = '/dev/ttyUSB0'
BOUDRATE = 57600
#ROBOT_URL = "ws://esp8266.local:81/"
ROBOT_URL = "ws://192.168.1.16:81/"

class RobotWebSocket():
    def __init__(self, url):
        self.websocket = websocket.WebSocket()
        self.url = url

    def __enter__(self):
        self.websocket.connect(self.url)
        return self.websocket

    def __exit__(self, type, value, traceback):
        self.websocket.close()

    def receive(self):
        return websocket.recv()

    def send(message):
        websocket.send(message)


class SimpleTest(unittest.TestCase):
    def setUp(self):
        self.robotUrl = ROBOT_URL
        self.commands = { "D" : "Received: ", "F" : "Forward" }

    def serialLogger(test):
        def wrapper(self):
            with serial.Serial(PORT, BOUDRATE, timeout=LOCAL_TIMEOUT) as ser:
                test(self)
                filename = "{}_{}.txt".format(time.strftime("%Y%m%d%H%M%S"), test.__name__)
                with open(filename, 'w') as file:
                    [file.write(str(elem)+ "\n") for elem in ser.readlines()]
        return wrapper

    @serialLogger
    @timeout_decorator.timeout(LOCAL_TIMEOUT)
    def testRunForward(self):
            with RobotWebSocket(self.robotUrl) as ws:
                ws.send("F")
                result = ws.recv()
            self.assertEqual(result, "Forward")

if __name__ == '__main__':
    unittest.main(warnings='ignore')


