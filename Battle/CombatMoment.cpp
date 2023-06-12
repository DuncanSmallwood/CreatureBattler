#ifndef COMBAT_MOMENT_CPP
#define COMBAT_MOMENT_CPP

#include "CombatMoment.h"

CombatMoment::CombatMoment(std::shared_ptr<Move> move, std::shared_ptr<Creature> sourceCreature, std::shared_ptr<Creature> targetCreature) {
	this->move = move;
	this->sourceCreature = sourceCreature;
	this->targetCreature = targetCreature;
}

std::shared_ptr<Move> CombatMoment::getMove() const{
	return move;
}

std::shared_ptr<Creature> CombatMoment::getSourceCreature() const{
	return sourceCreature;
}

std::shared_ptr<Creature> CombatMoment::getTargetCreature() const{
	return targetCreature;
}
#endif // COMBAT_MOMENT_CPP