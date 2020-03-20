#!/usr/bin/env python

from v1_two_axis.srv import *
from v1_two_axis.msg import *
import rospy

def talker():
    pub = rospy.Publisher('topic_limit_switch', LimitSwitch, queue_size=10)
    rospy.init_node('talker_limit_switch', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        userInput = input("Which motor to trip: ")
        rospy.loginfo("Sending motor %s limit switch to True", userInput)
        pub.publish(int(userInput), True)


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass