#ifndef TURN_H
#define TURN_H

#include <list>

#include "../CreatureModel/Creature.h"
#include "../CreatureModel/Move.h"
#include "CombatMoment.h"

class Turn {
private:
	Creature* creature1;
	Creature* creature2;
	Move* creature1Move;
	Move* creature2Move;

	std::list<CombatMoment> momentQueue;

public:
	Turn(Creature* creature1, Creature* creature2, Move* creature1Move, Move* creature2Move);
	~Turn();

	Turn& setCreature1(Creature* creature1);
	Turn& setCreature2(Creature* creature2);
	Creature* getCreature1();
	Creature* getCreature2();

	CombatMoment& nextMoment();
	bool moreMoments();
	void clearMoments(Creature* source);
};
#endif // TURN_H