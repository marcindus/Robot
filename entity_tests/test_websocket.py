import subprocess
import os
import unittest
import time, requests
import websocket
import serial
import time

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

    def send(self,message ):
        websocket.send(message)


class SimpleTest(unittest.TestCase):
    def setUp(self):
        self.robotUrl = "ws://192.168.1.10:81"
        self.commands = { "D" : "0", "F" : "Forward" }

    def serialLogger(test):
        def wrapper(self):
            with serial.Serial('/dev/ttyUSB0', 57600, timeout=3) as ser:
                test(self)
                filename = "{}_{}.txt".format(time.strftime("%Y%m%d%H%M%S"), test.__name__)
                with open(filename, 'w') as file:
                    [file.write(str(elem)+ "\n") for elem in ser.readlines()]
        return wrapper

    def testGetDistance(self):
        with RobotWebSocket(self.robotUrl) as ws:
            ws.send("D")
            result = ws.recv()
        self.assertEqual(result, self.commands["D"]) 

    @serialLogger
    def testRunForward(self):
            with RobotWebSocket(self.robotUrl) as ws:
                ws.send("F")
                result = ws.recv()
            self.assertEqual(result, self.commands["F"])

if __name__ == '__main__':
    unittest.main(warnings='ignore')


