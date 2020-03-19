#!/usr/bin/env python

def handle_home(req):
    mm.allReset()
    mm.setAllFinalSteps(75) # 135degrees left from vertical
    pub = rospy.Publisher('topic_blind_motor_command', BlindMotorCommand, queue_size=1)
    move_relative_talker(pub)
    mm.setAllFinalSteps(0)
    move_relative_talker(pub)

def callback_pipe_motor(data):
    motorRR.reset()
    motorRR.state = "moving"
    pub = rospy.Publisher('topic_blind_motor_command', BlindMotorCommand, queue_size=1)
    motorRR.previousTime = time.clock()
    while(motorRR.checkState("moving")):
        currentTime = time.clock()
        if (currentTime - motorRR.previousTime > data.time[motor.tupleIndex]):
            rospy.loginfo(motorRR.tupleIndex)
            print("motor: %s"%motor.motorIndex, "index: %s"%motor.tupleIndex, "direction sent: %s"%motor.stepTuple[motor.tupleIndex][3])
            pub.publish(motorRR.motorIndex,data.direction[motorRR.tupleIndex])
            motorRR.changeStep(motorRR.stepTuple[motorRR.tupleIndex][3])
            motorRR.tupleIndex = motorRR.tupleIndex + 1
            motorRR.previousTime = currentTime

def mains_server():
    rospy.init_node('pipe_motorRR')
    rospy.Subscriber("topic_pipe_motorRR", PipeStepList, callback_pipe_motor)
    rospy.
    # rospy.Subscriber("topic_pipe_motorRA", PipeStepList, callback_limit_switch)
    # s2 = rospy.Service("fetching_next_steps", NextStep, handle_steps_to_arduino)
    print("Ready to receive commands.")
    rospy.spin()

if __name__ == "__main__":
    motorRR = Motor.Motor(0)
    mains_server()