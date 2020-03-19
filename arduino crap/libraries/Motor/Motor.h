#ifndef Motor_h
#define Motor_h

/*provides stepper Motor control thru single steps*/

#include "Arduino.h"
#include <MD_CirQueue.h>

class Motor {
	public:
		Motor(int pulse, int direct, int limit, int CW, int CCW);

		void directionForward(); // CCW
		void directionBackward(); // CW
		void directionChange();
		void setDirection(bool incomingDir);

		void pulse();
		
		int getLimitPin();
		int getPreviousLimitValue();
		void setPreviousLimitValue(int incoming);

		int pushLimitValue(int incoming);
		bool checkLimitValues();
		void printLimitValues();

		void setStep(int incomingStep);
		int getStep();

		int getCWFlag();
		int getCCWFlag();

		unsigned long previousTime;
		
	private:
		
		int _pulsePin;
		int _directionPin;
		int _limitPin;
		int _previousLimitValue;

		int _limitValuesWritePointer = 0;
		static const int _limitValuesSize = 4;
		int _limitValues[_limitValuesSize] = {0,0,0,0};

		bool _direction;
		int _ccwFlag;
		int _cwFlag;

};

#endif