#ifndef COMBAT_MOMENT_H
#define COMBAT_MOMENT_H

#include <memory>

#include "../CreatureModel/Creature.h"
#include "../CreatureModel/Move.h"

class CombatMoment {
private:
	Move* move;
	Creature* sourceCreature;
	Creature* targetCreature;

public:
	CombatMoment(Move* move, Creature* sourceCreature, Creature* targetCreature);
	//CombatMoment(const CombatMoment& other);
	CombatMoment(CombatMoment&& other);

	Move* getMove() const;
	Creature* getSourceCreature() const;
	Creature* getTargetCreature() const;

	//CombatMoment& operator=(const CombatMoment& other);
	CombatMoment& operator=(CombatMoment&& other);
};
#endif // COMBAT_MOMENT_H
