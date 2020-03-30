import Point as p
import stepMath as smath

class MotorList(object):
    def __init__(self):
        # Arduino start reading bytes start at R0 motor, byte 103
        self._motorList = []
        self._currentPoint = p.Point(5,5)

    def append(self, motor):
        self._motorList.append(motor)

    def __len__(self):
        return len(self._motorList)

    def __getitem__(self, key):
        return self._motorList[key]

    def __setitem__(self, key, value):
        self._motorList[key] = value

    def __contains__(self, item):

        return True if item in [m.state for m in self._motorList] else False

    def __str__(self):
        return str([m.motorIndex for m in self._motorList])

    def setAllPreviousTimes(self, t):
        for m in self._motorList:
            m.previousTime = t

    def setAllStates(self, incomingState):
        for m in self._motorList:
            m.state = incomingState

    def setAllStepsToCCW(self):
        for m in self._motorList:
            m.step = m.CCW_endStep*smath.minorSteps
    
    def setAllFinalSteps(self, incomingStep):
        for m in self._motorList:
            m.moveRelativeFinalStep = incomingStep*smath.minorSteps

    def allIndicesInRange(self):
        sum = 0
        for m in self._motorList:
            if (not m.tupleIndexInRange()):
                sum += 1
        return (sum != len(self._motorList))

    def allReset(self):
        for m in self._motorList:
            m.reset()

    def checkAllStates(self, incomingState):
        for motor in self._motorList:
            if motor.state == incomingState:
                return True
        return False

    @property
    def currentPoint(self):
        return self._currentPoint

    @currentPoint.setter
    def currentPoint(self, incomingPoint):
        self._currentPoint = incomingPoint