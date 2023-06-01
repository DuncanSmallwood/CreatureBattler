#ifndef BATTLE_H
#define BATTLE_H

#include "../CreatureModel/Creature.h"
#include "CombatMoment.h"
#include "Turn.h"

class Battle {
private:
	Creature* creature1;
	Creature* creature2;

public:
	Battle(Creature* creature1, Creature* creature2);

	void doTurn(Move* creature1Move, Move* creature2Move);

private:
	unsigned int calculateDamage(double attack, double power, double defence) const;
};
#endif // BATTLE_H