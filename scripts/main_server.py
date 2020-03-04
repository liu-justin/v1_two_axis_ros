#!/usr/bin/env python

from v1_two_axis.srv import *
from v1_two_axis.msg import *
import rospy

import stepFinder as s
import pointFinder as p
import Motor
import MotorList
import math
import numpy as np
import time

def handle_endpoints_test(req):
    mm.allReset()
    first = p.Point(req.startPointX, req.startPointY)
    second = p.Point(req.endPointX, req.endPointY)
    p.linearTravel(first, second, mm)
    s.getSteps(mm)
    talker()
    # R0Time = [data[2] for data in mm[0].stepTuple]
    # R0Direction = [data[3] for data in mm[0].stepTuple]
    # RATime = [data[2] for data in mm[1].stepTuple]
    # RADirection = [data[3] for data in mm[1].stepTuple]
    return EndpointsTestResponse(mm[0].stepTuple != [])

# def handle_steps_to_arduino(req):
#     nextSet = mm[req.startByte].stepTuple.pop()
#     return NextStepResponse(nextSet[2], nextSet[3])

def endpoints_test_server():
    rospy.init_node('endpoints_test_server')
    s = rospy.Service('endpoints_test', EndpointsTest, handle_endpoints_test)
    # s2 = rospy.Service("fetching_next_steps", NextStep, handle_steps_to_arduino)
    print "Convert Endpoints to steps and start stepping."
    rospy.spin()

def talker():
    pub = rospy.Publisher('chatter_idx_dir', blind_idx_dir, queue_size=1)
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
                print(motor.tupleIndexInRange())
                print(motor.state)
                motor.previousTime = currentTime

# def talker():
#     pub = rospy.Publisher('chatter_idx_dir', blind_idx_dir, queue_size=1)
#     mm.setAllPreviousTime(time.clock())
#     while(mm.allIndicesInRange()):
#         for motor in [motor for motor in mm if motor.tupleIndexInRange()]:
#             currentTime = time.clock()
#             if (currentTime - motor.previousTime > motor.stepTuple[motor.tupleIndex][2]):
#                 rospy.loginfo(motor.stepTuple[motor.tupleIndex][3])
#                 print("motor: %s"%motor.motorIndex, "index: %s"%motor.tupleIndex, "direction sent: %s"%motor.stepTuple[motor.tupleIndex][3])
#                 pub.publish(motor.motorIndex, motor.stepTuple[motor.tupleIndex][3])
#                 motor.changeStep(motor.stepTuple[motor.tupleIndex][3])
#                 motor.tupleIndex += 1
#                 motor.previousTime = currentTime

if __name__ == "__main__":
    mm = MotorList.MotorList()
    R0 = Motor.Motor(mm)
    RA = Motor.Motor(mm)

    endpoints_test_server()