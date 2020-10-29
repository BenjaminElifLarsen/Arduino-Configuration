#!/usr/bin/python
import sys
import serial 
import time
threshold = 0
delayValue = 0
port = ''
if len(sys.argv) != 4:
    exit(-1)
threshold = int(sys.argv[1])
delayValue = int(sys.argv[2])
port = str(sys.argv[3])
if threshold < 0:
 threshold = 0
elif threshold > 1023:
 threshold = 1023
if delayValue < 0:
    delayValue = 0
print("Threshold: " + str(threshold))
print("Delay: " +  str(delayValue))
ser = serial.Serial()
ser.baudrate = 9600
ser.port = port
ser.open()
ser.write(bytes("D" + str(delayValue), 'ascii'))
print('Transmitted Delay')
time.sleep(2);
ser.write(bytes("T" + str(threshold), 'ascii'))
print('Transmitted Threshold')
ser.close()


exit(0)