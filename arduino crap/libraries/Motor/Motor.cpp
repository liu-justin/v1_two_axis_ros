#include "Arduino.h"
#include "Motor.h"
#include <MD_CirQueue.h>

Motor::Motor(int pulse, int direct, int limit) {
	_pulsePin = pulse;
	_directionPin = direct;
	_limitPin = limit;
	pinMode(_pulsePin, OUTPUT);
	pinMode(_directionPin, OUTPUT);
	pinMode(_limitPin, INPUT);
	_previousLimitValue = digitalRead(_limitPin);

}

// forward is positive angle, so CCW
// layout now, from left to right: black, green, red, blue
// I want to change it so directionForward goes CW, so im am switiching black and green
void Motor::directionForward() {
	_direction = true;
	digitalWrite(_directionPin, _direction);
}

// this is clockwise
void Motor::directionBackward() {
	_direction = false;
	digitalWrite(_directionPin, _direction);
}

void Motor::directionChange(){
	_direction = !_direction;
	digitalWrite(_directionPin, _direction);
}

// should be a 0 (directionBackwards) or 1(directionForwards) coming in
void Motor::setDirection(bool incomingDir) {
	_direction = incomingDir;
	digitalWrite(_directionPin, _direction);
}

void Motor::pulse(){
	digitalWrite(_pulsePin, HIGH);
	digitalWrite(_pulsePin, LOW);
}

int Motor::getLimitPin(){
	return _limitPin;
}

int Motor::getPreviousLimitValue(){
	return _previousLimitValue;
}

void Motor::setPreviousLimitValue(int incoming){
	_previousLimitValue = incoming;
}

int Motor::pushLimitValue() {
	_limitValues[_limitValuesWritePointer] = digitalRead(_limitPin);
	_limitValuesWritePointer++;
	if (_limitValuesWritePointer >= _limitValuesSize) {
		_limitValuesWritePointer = 0;
	}
	_previousLimitValue = _currentLimitValue;
	_currentLimitValue = checkLimitValues();
}

void Motor::printLimitValues() {
	for (int i = 0; i < _limitValuesSize; i++) {
		Serial.print(_limitValues[i]);
		Serial.print(", ");
	}
	Serial.println(" ");
}

bool Motor::limitValueChanged() {
	return _currentLimitValue != _previousLimitValue;
}

bool Motor::getCurrentLimitValue() {
	return _currentLimitValue;
}

bool Motor::checkLimitValues() {
	for (int i = 0; i < _limitValuesSize; i++) {
		if (_limitValues[i] == 1) return true;
	}
	return false;
}