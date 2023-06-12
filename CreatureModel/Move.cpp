#ifndef MOVE_CPP
#define MOVE_CPP

#include "Move.h"

Move::Move() {
	power = -1;
	accuracy = -1;
	type = MoveTypeEnum::AIR;
}

Move::Move(double power, double accuracy, MoveTypeEnum::MoveTypeEnum type) {
	this->power = power;
	this->accuracy = power;
	this->type = type;
}

Move& Move::setPower(double power) {
	this->power = power;
	return *this;
}

Move& Move::setAccuracy(double accuracy) {
	this->accuracy = accuracy;
	return *this;
}

Move& Move::setType(MoveTypeEnum::MoveTypeEnum type) {
	this->type = type;
	return *this;
}

double Move::getPower() {
	return power;
}

double Move::getAccuracy() {
	return accuracy;
}

MoveTypeEnum::MoveTypeEnum Move::getType() {
	return type;
}
#endif // MOVE_CPP