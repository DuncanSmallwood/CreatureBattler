#ifndef BATTLE_H
#define BATTLE_H

#include "../CreatureModel/Creature.h"
#include "CombatMoment.h"
#include "Turn.h"

class Battle {
private:
	std::shared_ptr<Creature> creature1;
	std::shared_ptr<Creature> creature2;

public:
	Battle(std::shared_ptr<Creature> creature1, std::shared_ptr<Creature> creature2);

	void doTurn(std::shared_ptr<Move> creature1Move, std::shared_ptr<Move> creature2Move);

private:
	unsigned int calculateDamage(double attack, double power, double defence) const;
};
#endif // BATTLE_H