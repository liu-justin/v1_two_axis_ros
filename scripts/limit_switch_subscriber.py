#!/usr/bin/env python
import rospy
from v1_two_axis.msg import *

def callback(data):
    # rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.direction)
    rospy.loginfo("I heard motorIndex: %s tripped: %s", data.motorIndex, data.tripped)
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("topic_limit_switch", LimitSwitch, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()