#!/usr/bin/env python

import sys
import rospy
from v1_two_axis.srv import *
import pointFinder as p
import stepFinder as s
import Motor
import MotorList

# import arduino_client as ac

def endpoints_test_client(startX, startY, endX, endY):
    rospy.wait_for_service('endpoints_test')
    try:
        # make sure this proxy is a different name than the server node
        endpoints_test_prox = rospy.ServiceProxy('endpoints_test', EndpointsTest)
        resp1 = endpoints_test_prox(startX, startY, endX, endY)
        print("Points in range: %s"%resp1.inRange)

        # ac.arduinoClientInit()
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def usage():
    return "%s [startX startY endX endY]"%sys.argv[0]

if __name__ == "__main__":
    print(sys.argv)
    if len(sys.argv) == 5:
        startX = float(sys.argv[1])
        startY = float(sys.argv[2])
        #startPoint = p.Point(startX, startY)
        endX = float(sys.argv[3])
        endY = float(sys.argv[4])
        #endPoint = p.Point(endX, endY)
    else:
        print usage()
        sys.exit(1)
    #print "startPoint: %s, endPoint: %s"%(startPoint,endPoint)
    endpoints_test_client(startX, startY, endX, endY)

    