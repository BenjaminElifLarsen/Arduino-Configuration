#!/usr/bin/python
import sys
import serial 
import serial.tools.list_ports
import time
threshold = 0
delayValue = 0
if len(sys.argv) != 4: #if no arguments are given, it should display all com ports. PySerial might have something you can use or the program sends out a message to all ports and wait for a while for an answer. If it gets an answer it will display the port(s)
    if len(sys.argv) == 1:
      #display ports here and then exit
     ports = list(serial.tools.list_ports.comports())
     portList = []
     for p in sorted(ports):
         if ("VID:PID" in p.hwid):
             #portList.append()
             #print("{}".format(str(p.description))) 
             #maybe for each port, try and connect then send a message and wait for some seconds. The arduiono should recive it and transmit data back. E.g. Python tranmit "H" and starts to listen for a response. If Arduino receives this waits like 3 seconds and transmit a "ey" back in bytes. 
             #testSer = serial.Serial(port=port,baudrate=9600,timeout=6)
             #testSer.close()
             testSer = serial.Serial(p.device,baudrate=9600,timeout=6 )
             #testSer.open()
             testSer.write(0)
             time.sleep(2)
             testSer.write(bytes("A" + str(100),'ascii'))
             response = testSer.read(9)
             #print(str(len(response)))
             #print(str(response))
             if len(response) > 0:
              portList.append("{}".format(str(p.description))) 
             testSer.close()
     for text in portList:
        print(str(text))
    exit(-1)
port = ''
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
ser.write(0)
time.sleep(2)
ser.write(bytes("D" + str(delayValue), 'ascii'))
print('Transmitted Delay')
time.sleep(2);
ser.write(bytes("T" + str(threshold), 'ascii'))
print('Transmitted Threshold')
ser.close()


exit(0)