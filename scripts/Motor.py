import stepMath as smath
import numpy as np
import math

class Motor(object):
    def __init__(self, motorIndex, CCW, CW):
        # Arduino start reading bytes start at R0 motor, byte 103
        # self.arduinoStartByte = self._motorIndex + 105
        self._motorIndex = motorIndex 
        self.arduinoStartByte = self._motorIndex + 105
        self.frameList = []
        self.stepTuple = [] #(time, step, time from last time, step from last step)
        self._tupleIndex = 1
        self.tupleIndexDeltaT = 0
        self.tupleIndexDirection = 0
        
        self.CCW_endStep = CCW
        self.CW_endStep = CW

        self.moveRelativeFinalStep = 0

        self.previousTime = 0

        self.step = 0 # this is the real step with minorStep
        self.state = "ready"

    def tupleStepsHalfwayBtwnChange(self):
        # appends the first step to the tupleStep list, deltaT is 0, and direction is 0
        stepIter = smath.nearestStep(self.frameList[0])
        self.stepTuple.append((0,stepIter,0,0))

        for i in range(len(self.frameList)-1):
            frameCurrent = self.frameList[i]
            frameNext = self.frameList[i+1]
            # counts number of half steps between steps, doesnt include the whole steps, only half steps
            stepsInFrame = smath.calcHalfStepsInFrame(frameCurrent, frameNext)
            #print(f"i: {i} frameCurrent: {frameCurrent} frameNext: {frameNext} stepsInFrame: {stepsInFrame}")

            if stepsInFrame > 0:

                # if there are any intersection points in the current frameTime, then grab them here
                for j in range(0, stepsInFrame):
                    s = self.stepTuple[-1][1] + smath.stepAngle*np.sign(frameNext - frameCurrent)
                    t = ((self.stepTuple[-1][1] + s)/2 - frameCurrent)/(frameNext - frameCurrent) * smath.frameTime + i*smath.frameTime
                    # deltaT = int(round(1000*(t - self.stepTuple[-1][0])))
                    deltaT = t - self.stepTuple[-1][0]
                    #####deltaS = int(np.sign(s - self.stepTuple[-1][1]))# maybe np.sign(frameNext - frameCurrent)
                    deltaS = s > self.stepTuple[-1][1]
                    
                    # want to keep steps under a set number(frame length*1000),
                    # so any deltaT that are greater than that set number is going to get cut down as evenly as possible
                    ##### self.appendFillerSteps(t,s,deltaT, deltaS)
                    self.stepTuple.append((t,s,deltaT,deltaS))

        s = smath.nearestStep(self.frameList[-1])
        t = smath.frameTime*(len(self.frameList)-1)
        # deltaT = int(round(1000*(t - self.stepTuple[-1][0])))
        deltaT = t - self.stepTuple[-1][0]
        #####deltaS = int(np.sign(s - self.stepTuple[-1][1]))
        deltaS = s > self.stepTuple[-1][1]
        ##### self.appendFillerSteps(t,s,deltaT, deltaS)
        self.stepTuple.append((t,s,deltaT,deltaS))

    def appendFillerSteps(self,t,s,deltaT, deltaS):

        divisor = int(deltaT//(smath.frameTime*1000))
        rounded = deltaT//(divisor+1)
        remainder = deltaT%(divisor+1)
        #print(rounded, remainder)
        for i in range(0,divisor):
            self.stepTuple.append((self.stepTuple[-1][0]+ rounded/1000 + (0 if remainder <= 0 else 0.001), self.stepTuple[-1][1], rounded + (0 if remainder <= 0 else 1), 121))
            remainder -= 1
        self.stepTuple.append((t, s, rounded, deltaS))
            #print(self.stepTuple)

    def tupleIndexInRange(self):
        return self._tupleIndex < len(self.stepTuple)
    
    def reset(self):
        self.frameList = []
        self.stepTuple = []
        self._tupleIndex = 1
        self.previousTime = 0

        self.moveRelativeFinalStep = 0

    def changeStep(self, directionBool):
        self.step += 2*(directionBool)-1

    def checkState(self, incomingState):
        return self.state == incomingState

    @property
    def motorIndex(self):
        return self._motorIndex

    @motorIndex.setter
    def motorIndex(self, mi):
        self._motorIndex = mi

    @property
    def tupleIndex(self):
        return self._tupleIndex

    @tupleIndex.setter
    def tupleIndex(self, newIndex):
        self._tupleIndex = newIndex  
        self.state = "moving" if self.tupleIndexInRange() else "ready"

    # this is messy, can fix this
    # @property
    # def step(self):
    #     return self._step

    # @step.setter
    # def step(self, newStep):
    #     self._step = newStep
