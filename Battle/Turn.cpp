#ifndef TURN_CPP
#define TURN_CPP

#include <list>

#include "Turn.h"
#include "..\include\rng\RandomManager.h"
// TODO: make it so the moment order is dynamic with speed boosts ect.
Turn::Turn(std::shared_ptr<Creature> creature1, std::shared_ptr<Creature> creature2, std::shared_ptr<Move> creature1Move, std::shared_ptr<Move> creature2Move) {
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

	std::shared_ptr<CombatMoment> moment1 = std::make_shared<CombatMoment>(creature1Move, creature1, creature2);
	std::shared_ptr<CombatMoment> moment2 = std::make_shared<CombatMoment>(creature2Move, creature2, creature1);
	if (creature1First) {
		momentQueue.push_back(moment1);
		momentQueue.push_back(moment2);
	}
	else{
		momentQueue.push_back(moment2);
		momentQueue.push_back(moment1);
	}
	
}


Turn& Turn::setCreature1(std::shared_ptr<Creature> creature) {
	creature1 = creature;
	return *this;
}

Turn& Turn::setCreature2(std::shared_ptr<Creature> creature) {
	creature2 = creature;
	return *this;
}

std::shared_ptr<Creature> Turn::getCreature1() const{
	return creature1;
}

std::shared_ptr<Creature> Turn::getCreature2() const {
	return creature2;
}


std::shared_ptr<CombatMoment> Turn::nextMoment() {
	std::shared_ptr<CombatMoment> nextMoment = momentQueue.front();
	momentQueue.erase(momentQueue.begin());
	return nextMoment;
}

bool Turn::moreMoments() {
	return !momentQueue.empty();
}

void Turn::clearMoments(const Creature& source) {
	for (std::list<std::shared_ptr<CombatMoment>>::iterator it = momentQueue.begin(); it != momentQueue.end();) {
		if (*it->get()->getSourceCreature() == source) {
			it = momentQueue.erase(it);
		}
		else {
			++it;
		}
	}
}
#endif // TURN_CPP