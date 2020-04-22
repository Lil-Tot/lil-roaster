#!/bin/python3
import sys, serial
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)

if(ser.isOpen() == False):
    ser.open()

serialout = str(ser.readline())
print(serialout[2:-5])

ser.close()
