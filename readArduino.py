import serial
import time
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Port
port = '/dev/cu.usbmodem1101'
usb = serial.Serial(port)
f = open('arduinoB1_6', 'w')

#variables
#t = []
#x = []
n = 0

#loop
while(n < 50):
    arduino = usb.readline().rstrip()
    #print(n, arduino.decode())
    f.write('{}\n'.format(arduino.decode()))
    #data = arduino.decode().split(",")
    #x.append(data[1])
    #t.append(data[0])
    n = n+1

df = pd.read_csv('arduinoB1_6.csv')


plt.plot(t, x, '.')
plt.show()