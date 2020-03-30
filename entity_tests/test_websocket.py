import subprocess
import os
import unittest
import time, requests
import websocket

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

    def testGetDistance(self):
        with RobotWebSocket(self.robotUrl) as ws:
            ws.send("D")
            result = ws.recv()
        self.assertEqual(result, self.commands["D"]) 

    def testRunForward(self):
        with RobotWebSocket(self.robotUrl) as ws:
            ws.send("F")
            result = ws.recv()
        self.assertEqual(result, self.commands["F"]) 

if __name__ == '__main__':
    unittest.main(warnings='ignore')


