#ifndef COMBAT_MOMENT_H
#define COMBAT_MOMENT_H

#include "..\CreatureModel\Creature.h"
#include "..\CreatureModel\Move.h"

class CombatMoment {
private:
	std::shared_ptr<Move> move;
	std::shared_ptr<Creature> sourceCreature;
	std::shared_ptr<Creature> targetCreature;

public:
	CombatMoment(std::shared_ptr<Move> move, std::shared_ptr<Creature> sourceCreature, std::shared_ptr<Creature> targetCreature);

	std::shared_ptr<Move> getMove() const;
	std::shared_ptr<Creature> getSourceCreature() const;
	std::shared_ptr<Creature> getTargetCreature() const;
};
#endif // COMBAT_MOMENT_H