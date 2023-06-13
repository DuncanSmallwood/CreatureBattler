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
	this->accuracy = accuracy;
	this->type = type;
}

Move::Move(const Move& other) {
	power = other.power;
	accuracy = other.accuracy;
	type = other.type;
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