import Point as p
import stepMath as smath

class MotorManager(object):

    def addMotor(self, **kwargs):
        # self.csDict.update(kwargs)
        # for cs in kwargs.values():
        #     self.pointNames.extend(cs.points.keys())
        
        # replaced __dict__ with vars(self)
        vars(self).update(kwargs)

    # check if the state is in mm
    def __contains__(self, item):
        return True if item in [m.state for m in vars(self).values()] else False

    def setAllPreviousTimes(self, t):
        for m in vars(self).values():
            m.previousTime = t

    def setAllStates(self, incomingState):
        for m in vars(self).values():
            m.state = incomingState

    def setAllStepsToCCW(self):
        for m in vars(self).values():
            m.step = m.CCW_endStep*smath.minorSteps
    
    def setAllFinalSteps(self, incomingStep):
        for m in vars(self).values():
            m.moveRelativeFinalStep = incomingStep*smath.minorSteps

    def allIndicesInRange(self):
        sum = 0
        for m in vars(self).values():
            if (not m.tupleIndexInRange()):
                sum += 1
        return (sum != len(vars(self)))

    def allReset(self):
        for m in vars(self).values():
            m.reset()

    def checkAllStates(self, incomingState):
        for motor in vars(self).values():
            if motor.state == incomingState:
                return True
        return False