#ifndef Motor_h
#define Motor_h

/*provides stepper Motor control thru single steps*/

#include "Arduino.h"

class Motor {
	public:
		Motor(int pulse, int direct, int limit, int CW, int CCW);

		void directionForward(); // CCW
		void directionBackward(); // CW
		void directionChange();
		void setDirection(bool incomingDir);

		void pulse();
		
		int getLimitPin();

		void setStep(int incomingStep);
		int getStep();
		
		void setState(int incomingState);
		int getState();
		int getStatePrevious();
		void revertState();

		int getCWFlag();
		int getCCWFlag();

		void decrementRelativeMoveCounter();
		int getRelativeMoveCounter();
		void setRelativeMoveCounter(int incomingCounter);

		unsigned long previousTime;
		
	private:
		
		int _pulsePin;
		int _directionPin;
		int _limitPin;

		int _relativeMoveCounter;
		bool _direction;
		int _step;
		int _state;
		int _statePrevious;
		int _ccwFlag;
		int _cwFlag;

};

#endif