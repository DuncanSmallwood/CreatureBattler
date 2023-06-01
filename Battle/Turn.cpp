#ifndef TURN_CPP
#define TURN_CPP

#include <list>

#include "Turn.h"
#include "..\include\rng\RandomManager.h"
// TODO: make it so the moment order is dynamic with speed boosts ect.
Turn::Turn(Creature* creature1, Creature* creature2, Move* creature1Move, Move* creaure2Move) {
	this->creature1 = creature1;
	this->creature2 = creature2;
	this->creature1Move = creature1Move;
	this->creature2Move = creature2Move;

	double c1Speed = creature1->getSpeed();
	double c2Speed = creature2->getSpeed();

	bool creature1First;
	if (c1Speed == c2Speed)
		creature1First = RandomManager::d2();
	else
		creature1First = c1Speed > c2Speed;

	CombatMoment* moment1;
	CombatMoment* moment2;
	if (creature1First) {
		moment1 = new CombatMoment(creature1Move, creature1, creature2);
		moment2 = new CombatMoment(creature2Move, creature2, creature1);
	}
	else{
		moment1 = new CombatMoment(creature2Move, creature2, creature1);
		moment2 = new CombatMoment(creature1Move, creature1, creature2);
	}
	momentQueue.push_back(*moment1);
	momentQueue.push_back(*moment2);
}

Turn::~Turn() {
	if (creature1Move) {
		delete creature1Move;
		creature1Move = NULL;
	}
	if (creature2Move) {
		delete creature2Move;
		creature2Move = NULL;
	}
}


Turn& Turn::setCreature1(Creature* creature) {
	if (creature1) {
		delete creature1;
	}
	creature1 = creature;
	return *this;
}

Turn& Turn::setCreature2(Creature* creature) {
	if (creature2) {
		delete creature2;
	}
	creature2 = creature;
	return *this;
}

Creature* Turn::getCreature1() {
	return this->creature1;
}

Creature* Turn::getCreature2() {
	return this->creature2;
}


CombatMoment& Turn::nextMoment() {
	CombatMoment* nextMoment = &momentQueue.front();
	momentQueue.erase(momentQueue.begin());
	return *nextMoment;
}

bool Turn::moreMoments() {
	return momentQueue.empty();
}

void Turn::clearMoments(Creature* source) {
	for (std::list<CombatMoment>::iterator it = momentQueue.begin(); it != momentQueue.end();) {
		if (*it->getSourceCreature() == *source) {
			it = momentQueue.erase(it);
		}
		else {
			++it;
		}
	}
}
#endif // TURN_CPP