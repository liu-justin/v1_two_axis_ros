#!/usr/bin/env python

from v1_two_axis.srv import *
from v1_two_axis.msg import *
import rospy

import stepFinder as s
import pointFinder as pf
import Point as p
import stepMath as smath
import Motor
import MotorList
import math
import numpy as np
import time
import CoordinateSystemConstants as csc
import CoordinateSystem as cs

def handle_move_point(req):
    mm.allReset()
    endPoint = p.Point(req.pointX, 0,  req.pointY)
    pf.linearTravel(csm, mm, mm.currentPoint, endPoint)
    s.getSteps(mm)
    pub = rospy.Publisher('topic_blind_motor_command', BlindMotorCommand, queue_size=1)
    move_point_talker(pub)
    mm.currentPoint = endPoint
    return MovePointResponse("moving to point done, ending double service")

def handle_home(req):
    mm.allReset()
    pub = rospy.Publisher('topic_blind_motor_command', BlindMotorCommand, queue_size=1)
    rospy.loginfo("setting all final steps to -75, hoping to hit the limit switch")
    mm.setAllFinalSteps(-75) # 135degrees left from vertical
    move_relative_talker(pub)

    rospy.loginfo("Setting all steps to the CCW endstep")
    mm.setAllStepsToCCW()

    rospy.loginfo("setting all goal steps to 0")
    mm.setAllFinalSteps(0)

    rospy.loginfo("getting off of the limit switch with 5 blind steps CW")
    move_relative_off_limit_switch(pub)

    move_relative_talker(pub)
    # mm.currentPoint = 
    return HomeResponse("done with homing")

def callback_limit_switch(data):
    print(data)
    if data.tripped:
        mm[data.motorIndex].state = "error" 
        rospy.loginfo("motor %s has hit a limit switch", data.motorIndex)

def move_point_talker(pub):
    mm.setAllStates("moving")
    mm.setAllPreviousTimes(time.clock())
    while(mm.checkAllStates("moving")):
        for motor in [motor for motor in mm if motor.checkState("moving")]:
            currentTime = time.clock()
            if (currentTime - motor.previousTime > motor.stepTuple[motor.tupleIndex][2]):
                rospy.loginfo("motor: %s step: %s moveRelativeFinalStep: %s", motor.motorIndex, motor.step, motor.moveRelativeFinalStep)
                # print("motor: %s"%motor.motorIndex, "index: %s"%motor.tupleIndex, "direction sent: %s"%motor.stepTuple[motor.tupleIndex][3])
                pub.publish(motor.motorIndex, motor.stepTuple[motor.tupleIndex][3])
                motor.changeStep(motor.stepTuple[motor.tupleIndex][3])
                motor.tupleIndex = motor.tupleIndex + 1 # changing tupleIndex checks the state as well
                motor.previousTime = currentTime

def move_relative_talker(pub):
    mm.setAllStates("moving")
    mm.setAllPreviousTimes(time.clock())
    while(mm.checkAllStates("moving")):
        for motor in [motor for motor in mm if motor.checkState("moving")]:
            currentTime = time.clock()
            if (currentTime - motor.previousTime > smath.homingInterval):
                rospy.loginfo("motor: %s step: %s moveRelativeFinalStep: %s published direction: %s", motor.motorIndex, motor.step, motor.moveRelativeFinalStep, motor.moveRelativeFinalStep > motor.step)
                # print("motor: %s"%motor.motorIndex, "step: %s"%motor.step, "moveRelativeFinalStep: %s"%motor.moveRelativeFinalStep)
                pub.publish(motor.motorIndex, motor.moveRelativeFinalStep > motor.step) # want to go CCW, or negative in steps to home
                motor.changeStep(motor.moveRelativeFinalStep > motor.step)
                if (motor.step == motor.moveRelativeFinalStep): # this is messy, can fix this with properties in setting step
                    rospy.loginfo("setting motor %s state to ready!", motor.motorIndex)
                    motor.state = "ready"
                motor.previousTime = currentTime

def move_relative_off_limit_switch(pub):
    mm.setAllStates("moving")
    mm.setAllPreviousTimes(time.clock())
    offLimitSwitchSteps = 40
    while(offLimitSwitchSteps >= 0):
        for motor in mm:
            currentTime = time.clock()
            if (currentTime - motor.previousTime > smath.homingInterval):
                rospy.loginfo("motor: %s step: %s moveRelativeFinalStep: %s", motor.motorIndex, motor.step, motor.moveRelativeFinalStep)
                pub.publish(motor.motorIndex, True) # want to go CCW, or negative in steps to home
                motor.changeStep(True)
                offLimitSwitchSteps -= 1
                motor.previousTime = currentTime

def mains_server():
    rospy.init_node('mains_server')
    move_point_server = rospy.Service('move_point_service', MovePoint, handle_move_point)
    home_server = rospy.Service('home_service', Home, handle_home)
    rospy.Subscriber("topic_limit_switch", LimitSwitch, callback_limit_switch)
    # s2 = rospy.Service("fetching_next_steps", NextStep, handle_steps_to_arduino)
    print("Ready to receive commands.")
    rospy.spin()

if __name__ == "__main__":
    mm = MotorList.MotorList()
    RR = Motor.Motor(mm, -52, 8)
    RA = Motor.Motor(mm, -26, 15)
    csm = cs.coordinateSystemManager(csc.mainCS)
    csm.addCoordinateSystem(motorRC = csc.motorRC, motorRR = csc.motorRR, motorRT = csc.motorRT)

    mains_server()