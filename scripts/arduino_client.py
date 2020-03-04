#!/usr/bin/env python

import sys
import rospy
from v1_two_axis.srv import *
import pointFinder as p
import stepFinder as s
import Motor
import MotorList
import serial

# for the comport, look in Arduino IDE when the arduino is connected
ser = serial.Serial("COM5", 57600)

def waitForArduino(passcode):
	msg = ser.read().decode("unicode_escape")
	
	while not msg.endswith(passcode):
		msg += ser.read().decode("unicode_escape")
		if (msg.endswith('~')):
			#print(f"Periodic update: {msg}")
			msg = ""

	#print(msg)

def communicateWithArduino():
	index = int.from_bytes(ser.read(), byteorder='big')
	response = fetchStepsClient(index)
	time = response.time
	direction = response.direction
	# if (direction == 2):
	# 	break

	ser.write((index).to_bytes(1, byteorder='big'))
	ser.write((time).to_bytes(1, byteorder="big"))
	ser.write((direction).to_bytes(1, byteorder="big"))

def initiateWithArduino(motorList):
	for i in range(4):
		response = fetchStepsClient(i%2)
		time = response.time
		direction = response.direction

		ser.write((m.startByte).to_bytes(1, byteorder='big'))
		ser.write((time).to_bytes(1, byteorder="big"))
		ser.write((direction).to_bytes(1, byteorder="big"))
	#waitForArduino("}")

# since I only have one arduino now, I'll just use my previous code
# but to use two arduinos, I can use two arduino services for each of the motors
def fetchStepsClient(startByte):
    rospy.wait_for_service('steps_to_arduino')
    try:
        fetching_next_steps = rospy.ServiceProxy('fetching_next_steps', NextStep)
        response = fetching_next_steps(startByte)
        return response
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def arduinoClientInit():
	waitForArduino("{")
	initiateWithArduino()
	while(1==1):
		communicateWithArduino()