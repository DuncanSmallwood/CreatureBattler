#ifndef COMBAT_MOMENT_H
#define COMBAT_MOMENT_H

#include "..\CreatureModel\Creature.h"
#include "..\CreatureModel\Move.h"

class CombatMoment {
private:
	Move* move;
	Creature* sourceCreature;
	Creature* targetCreature;

public:
	CombatMoment(Move* move, Creature* sourceCreature, Creature* targetCreature);

	Move* getMove() const;
	Creature* getSourceCreature() const;
	Creature* getTargetCreature() const;
};
#endif // COMBAT_MOMENT_H