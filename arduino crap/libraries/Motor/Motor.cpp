#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pulse, int direct, int limit, int CW, int CCW) {
	_pulsePin = pulse;
	_directionPin = direct;
	_limitPin = limit;
	pinMode(_pulsePin, OUTPUT);
	pinMode(_directionPin, OUTPUT);
	pinMode(_limitPin, INPUT);

	_ccwFlag = CCW;
	_cwFlag = CW;

	_state = 1;
	_statePrevious = 1;
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
}

void Motor::setStep(int incomingStep) {
	_step = incomingStep;
}

int Motor::getStep() {
	return _step;
}

void Motor::pulse(){
	digitalWrite(_pulsePin, HIGH);
	digitalWrite(_pulsePin, LOW);
	_step += (2*_direction)-1;
}

void Motor::setState(int incomingState) {
	_statePrevious = _state;
	_state = incomingState;
	// Serial.print("Setting state to ");
	// Serial.println(incomingState);
}

int Motor::getState() {
	return _state;
}

int Motor::getStatePrevious() {
	return _statePrevious;
}

void Motor::revertState() {
	_state = _statePrevious;
}

int Motor::getCCWFlag() {
	return _ccwFlag;
}

int Motor::getCWFlag() {
	return _cwFlag;
}

int Motor::getLimitPin(){
	return _limitPin;
}

int Motor::getRelativeMoveCounter() {
	return _relativeMoveCounter;
}

void Motor::setRelativeMoveCounter(int incomingCounter) {
	_relativeMoveCounter = incomingCounter;
}

void Motor::decrementRelativeMoveCounter() {
	_relativeMoveCounter -= 1;
}