#ifndef BATTLE_H
#define BATTLE_H

#include <memory>

#include "../CreatureModel/Creature.h"
#include <CombatMoment.h>
#include <Turn.h>

class Battle {
private:
	std::unique_ptr<Creature> creature1;
	std::unique_ptr<Creature> creature2;

public:
	Battle(const Creature& creature1, const Creature& creature2);
	Battle(Creature* creature1, Creature* creature2);

	void doTurn(Move* creature1Move, Move* creature2Move);

	// simple getter here is probably too porous
	std::pair<Creature, Creature> viewCreatures();

private:
	unsigned int calculateDamage(double attack, double power, double defence) const;
};
#endif // BATTLE_H
