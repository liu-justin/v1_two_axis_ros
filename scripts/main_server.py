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

def handle_move_point(req):
    mm.allReset()
    endPoint = p.Point(req.pointX, req.pointY)
    p.linearTravel(mm.currentPoint, endPoint, mm)
    s.getSteps(mm)
    talker()
    return MovePointResponse("moving to point done, ending double service")

def handle_home(req):
    mm.allReset()
    endPoint = p.Point(0, 10)
    p.linearTravel(mm.currentPoint, endPoint, mm)
    s.getSteps(mm)
    talker()

def mains_server():
    rospy.init_node('mains_server')
    move_point_server = rospy.Service('move_point_service', MovePoint, handle_move_point)
    home_server = rospy.Service('home_service', Home, handle_home)
    # rospy.Subscriber("chatter_limit_switch", limit_switched, "send motor index to error")
    # s2 = rospy.Service("fetching_next_steps", NextStep, handle_steps_to_arduino)
    print("Ready to receive commands.")
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

if __name__ == "__main__":
    mm = MotorList.MotorList()
    R0 = Motor.Motor(mm)
    RA = Motor.Motor(mm)

    mains_server()