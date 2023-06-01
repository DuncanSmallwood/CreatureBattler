#ifndef MOVE_H
#define MOVE_H

#include "Enum/MoveTypeEnum.cpp"

class Move {
private:
	double power;
	double accuracy;
	MoveTypeEnum::MoveTypeEnum type;

public:
	Move();
	Move(double power, double accuracy, MoveTypeEnum::MoveTypeEnum type);

	Move& setPower(double power);
	Move& setAccuracy(double power);
	Move& setType(MoveTypeEnum::MoveTypeEnum type);

	double getPower();
	double getAccuracy();
	MoveTypeEnum::MoveTypeEnum getType();
};
#endif // MOVE_H