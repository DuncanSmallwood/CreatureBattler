#ifndef TURN_H
#define TURN_H

#include <list>
#include <memory>

#include "../CreatureModel/Creature.h"
#include "../CreatureModel/Move.h"
#include "CombatMoment.h"

class Turn {
private:
	Creature* creature1;
	Creature* creature2;
	Move* creature1Move;
	Move* creature2Move;

	std::list<std::shared_ptr<CombatMoment>> momentQueue;

public:
	Turn(Creature* creature1, Creature* creature2, Move* creature1Move, Move* creature2Move);

	Turn& setCreature1(Creature* creature1);
	Turn& setCreature2(Creature* creature2);
	Creature* getCreature1() const;
	Creature* getCreature2() const;

	std::shared_ptr<CombatMoment> nextMoment();
	bool moreMoments();
	void clearMoments(const Creature& source);
};
#endif // TURN_H
