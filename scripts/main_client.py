#!/usr/bin/env python

import sys
import rospy
from v1_two_axis.srv import *
import pointFinder as p
import stepFinder as s
import Motor
import MotorList

# import arduino_client as ac

def move_point_client(endX, endY):
    rospy.wait_for_service('move_point_service')
    try:
        # make sure this proxy is a different name than the server node
        move_point_prox = rospy.ServiceProxy('move_point', EndpointsTest)
        resp1 = move_point_prox(startX, startY, endX, endY)
        print("Points in range: %s"%resp1.inRange)

        # ac.arduinoClientInit()
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def mains_client(incomingCommand): # just to make it different from the name of the file, if that has anything to do with it
    rospy.wait_for_service('move_point_service')
    rospy.wait_for_service('home_service')
    try:
        commandedService = incomingCommand[0] + "_service"
        prox = rospy.ServiceProxy(commandedService, commandDict[incomingCommand[0]])
        # removing the first part of the incomingCommand, the string command so that the rest of the list can be passed in prox as args
        incomingCommand.pop(0)
        response = prox(*incomingCommand)
        print(response)

    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

commandDict = {"home": Home, "move_point": MovePoint, "move_direction":("orthogonal_direction", "distance"), "move_angle":("RRangleTo", "RAangleTo")}

# split it, if there are additional args for points then convert into appropriate types
def formatForUse(userCommand):
    userCommand = userCommand.split()
    if len(userCommand) > 1:
        userCommand[1] = float(userCommand[1])
        userCommand[2] = float(userCommand[2])
    return userCommand
    # for item in userCommand:
    #     if item.isnumeric(): # contains 0-9 or . have to write that regex since isnumeric doesn't work
    #         item = float(item)

if __name__ == "__main__":
    while True:
        userCommand = raw_input("Enter your command, and its args: ")
        print(userCommand)
        # userCommand = userCommand.split()
        userCommand = formatForUse(userCommand)
        print(userCommand)
        
        if userCommand[0] in list(commandDict.keys()): 
            mains_client(userCommand)
            # if (len(userCommand)-1 == len(commandDict[userCommand[0]])):
            #     mains_client(userCommand)
            # else:
            #     print "Enter the correct number of args: %s"%commandDict[userCommand[0]]
        else:
            print "Error: command must be one in the following list: "
            print commandDict.keys()

