#!/usr/bin/python
import sys
import serial 
import time
threshold = 0
delayValue = 0
port = ''
if len(sys.argv) == 4:
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
print(str(ser))
i = 0
ser.write(0)
text = ser.read(6)
ser.write(bytes("D" + str(delayValue), 'utf-8'))
print('Transmitted Delay')
text = ser.read(6)
print("Test: " + str(text[0]) + ' ' + str(text[1]) + ' ' + str(text[2]) + ' ' + str(text[3]) + ' ' + str(text[4]) + ' ' + str(text[5]))  #text.decode('utf-8')
#time.sleep(1000);
ser.write(bytes("T" + str(threshold), 'utf-8'))
print('Transmitted Threshold')
text = ser.read(6)
print("Test: " + str(text[0]) + ' ' + str(text[1]) + ' ' + str(text[2]) + ' ' + str(text[3]) + ' ' + str(text[4]) + ' ' + str(text[5]))  #text.decode('utf-8')
while True:
 text = ser.read(6)
 i += 1
 print("Test: " + str(text[0]) + ' ' + str(text[1]) + ' ' + str(text[2]) + ' ' + str(text[3]) + ' ' + str(text[4]) + ' ' + str(text[5]))  #text.decode('utf-8')
ser.close()


exit(0)