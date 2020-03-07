#!/usr/bin/env python

from v1_two_axis.srv import *
from v1_two_axis.msg import *
import rospy

import stepFinder as s
import pointFinder as p
import stepMath as smath
import Motor
import MotorList
import math
import numpy as np
import time

def handle_move_point(req):
    mm.allReset()
    endPoint = p.Point(req.pointX, req.pointY)
    p.linearTravel(mm.currentPoint, endPoint, mm)
    s.getSteps(mm)
    pub = rospy.Publisher('topic_blind_motor_command', BlindMotorCommand, queue_size=1)
    move_point_talker(pub)
    return MovePointResponse("moving to point done, ending double service")

def handle_home(req):
    mm.allReset()
    mm.setAllFinalSteps(75) # 135degrees left from vertical
    pub = rospy.Publisher('topic_blind_motor_command', BlindMotorCommand, queue_size=1)
    move_relative_talker(pub)
    mm.setAllFinalSteps(0)
    move_relative_talker(pub)

def callback_limit_switch(data):
    print(data)
    if data.tripped:
        mm[data.motorIndex].state = "error" 

def mains_server():
    rospy.init_node('mains_server')
    move_point_server = rospy.Service('move_point_service', MovePoint, handle_move_point)
    home_server = rospy.Service('home_service', Home, handle_home)
    rospy.Subscriber("topic_limit_switch", LimitSwitch, callback_limit_switch)
    # s2 = rospy.Service("fetching_next_steps", NextStep, handle_steps_to_arduino)
    print("Ready to receive commands.")
    rospy.spin()

def move_point_talker(pub):
    mm.setAllStates("moving")
    mm.setAllPreviousTimes(time.clock())
    while(mm.checkAllStates("moving")):
        for motor in [motor for motor in mm if motor.checkState("moving")]:
            currentTime = time.clock()
            if (currentTime - motor.previousTime > motor.stepTuple[motor.tupleIndex][2]):
                rospy.loginfo(motor.stepTuple[motor.tupleIndex][3])
                print("motor: %s"%motor.motorIndex, "index: %s"%motor.tupleIndex, "direction sent: %s"%motor.stepTuple[motor.tupleIndex][3])
                pub.publish(motor.motorIndex, motor.stepTuple[motor.tupleIndex][3])
                motor.changeStep(motor.stepTuple[motor.tupleIndex][3])
                motor.tupleIndex = motor.tupleIndex + 1
                motor.previousTime = currentTime

def move_relative_talker(pub):
    mm.setAllStates("moving")
    mm.setAllPreviousTimes(time.clock())
    while(mm.checkAllStates("moving")):
        for motor in [motor for motor in mm if motor.checkState("moving")]:
            currentTime = time.clock()
            if (currentTime - motor.previousTime > smath.homingInterval):
                pub.publish(motor.motorIndex, motor.relativeMoveFinalStep < motor.step) # want to go CCW, or negative in steps to home
                motor.changeStep(motor.relativeMoveFinalStep > motor.step)
                if (motor.step == motor.relativeMoveFinalStep): # this is messy, can fix this
                    motor.state = "ready"
                motor.previousTime = currentTime


if __name__ == "__main__":
    mm = MotorList.MotorList()
    R0 = Motor.Motor(mm)
    RA = Motor.Motor(mm)

    mains_server()