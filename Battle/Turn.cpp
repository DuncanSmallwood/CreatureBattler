#include <list>

#include "Turn.h"
#include "../include/rng/RandomManager.h"
// TODO: make it so the moment order is dynamic with speed boosts ect.
Turn::Turn(Creature* creature1, Creature* creature2, Move* creature1Move, Move* creature2Move) {
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

	CombatMoment* moment1 = new CombatMoment(creature1Move, creature1, creature2);
	CombatMoment* moment2 = new CombatMoment(creature2Move, creature2, creature1);
	if (creature1First) {
		momentQueue.push_back(moment1);
		momentQueue.push_back(moment2);
	}
	else{
		momentQueue.push_back(moment2);
		momentQueue.push_back(moment1);
	}
	
}

Turn::~Turn(){
	for(std::list<CombatMoment*>::iterator it = momentQueue.begin(); it != momentQueue.end(); it++){
		if (*it)
			delete *it;
		momentQueue.erase(it);
	}
}

Turn& Turn::setCreature1(Creature* creature) {
	creature1 = creature;
	return *this;
}

Turn& Turn::setCreature2(Creature* creature) {
	creature2 = creature;
	return *this;
}

Creature* Turn::getCreature1() const{
	return creature1;
}

Creature* Turn::getCreature2() const {
	return creature2;
}


// TODO:This may be evidence that these CombatMoments need to be shared_ptr objects
std::unique_ptr<CombatMoment> Turn::nextMoment() {
	std::unique_ptr<CombatMoment> nextMoment(momentQueue.front());
	momentQueue.erase(momentQueue.begin());
	return nextMoment;
}

bool Turn::moreMoments() {
	return !momentQueue.empty();
}

void Turn::clearMoments(const Creature& source) {
	for (std::list<CombatMoment*>::iterator it = momentQueue.begin(); it != momentQueue.end();) {
		if (*(**it).getSourceCreature() == source) {
			delete *it;
			it = momentQueue.erase(it);
		}
		else {
			++it;
		}
	}
}
