import time
import serial

ser = serial.Serial('COM4', 9600)
time.sleep(2)

# Read and record the data
data =[]                       # empty list to store the data
for i in range(50):
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode  
    string = string_n.rstrip() # remove \n and \r
    print(string)
  #  flt = float(string)        # convert string to float
   # print(flt)
    #data.append(flt)           # add to the end of data list
   # time.sleep(0.1)            # wait (sleep) 0.1 seconds

ser.close()

#for line in data:
   # print(line)

#import matplotlib.pyplot as plt

#plt.plot(data)
#plt.xlabel('Time (seconds)')
#plt.ylabel('Potentiometer Reading')
#plt.title('Potentiometer Reading vs. Time')
#plt.show()