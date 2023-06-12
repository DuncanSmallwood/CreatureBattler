#ifndef TURN_H
#define TURN_H

#include <list>

#include "../CreatureModel/Creature.h"
#include "../CreatureModel/Move.h"
#include "CombatMoment.h"

class Turn {
private:
	std::shared_ptr<Creature> creature1;
	std::shared_ptr<Creature> creature2;
	std::shared_ptr<Move> creature1Move;
	std::shared_ptr<Move> creature2Move;

	std::list<std::shared_ptr<CombatMoment>> momentQueue;

public:
	Turn(std::shared_ptr<Creature> creature1, std::shared_ptr<Creature> creature2, std::shared_ptr<Move> creature1Move, std::shared_ptr<Move> creature2Move);

	Turn& setCreature1(std::shared_ptr<Creature> creature1);
	Turn& setCreature2(std::shared_ptr<Creature> creature2);
	std::shared_ptr<Creature> getCreature1() const;
	std::shared_ptr<Creature> getCreature2() const;

	std::shared_ptr<CombatMoment> nextMoment();
	bool moreMoments();
	void clearMoments(const Creature& source);
};
#endif // TURN_H