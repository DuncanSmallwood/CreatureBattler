#ifndef COMBAT_MOMENT_CPP
#define COMBAT_MOMENT_CPP

#include "CombatMoment.h"

CombatMoment::CombatMoment(Move* move, Creature* sourceCreature, Creature* targetCreature) {
	this->move = move;
	this->sourceCreature = sourceCreature;
	this->targetCreature = targetCreature;
}

Move* CombatMoment::getMove() const{
	return move;
}

Creature* CombatMoment::getSourceCreature() const{
	return sourceCreature;
}

Creature* CombatMoment::getTargetCreature() const{
	return targetCreature;
}
#endif // COMBAT_MOMENT_CPP