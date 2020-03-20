#ifndef Motor_h
#define Motor_h

/*provides stepper Motor control thru single steps*/

#include "Arduino.h"
#include <MD_CirQueue.h>

class Motor {
	public:
		Motor(int pulse, int direct, int limit);

		void directionForward(); // CCW
		void directionBackward(); // CW
		void directionChange();
		void setDirection(bool incomingDir);

		void pulse();
		
		int getLimitPin();
		int getPreviousLimitValue();
		void setPreviousLimitValue(int incoming);

		int pushLimitValue();
		bool checkLimitValues();
		void printLimitValues();
		bool limitValueChanged();
		bool getCurrentLimitValue();

		void setStep(int incomingStep);
		int getStep();

		unsigned long previousTime;
		
	private:
		
		int _pulsePin;
		int _directionPin;
		int _limitPin;
		int _previousLimitValue;
		int _currentLimitValue;

		int _limitValuesWritePointer = 0;
		static const int _limitValuesSize = 20;
		int _limitValues[_limitValuesSize] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		bool _direction;

};

#endif