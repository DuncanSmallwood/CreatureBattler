#ifndef BATTLE_CPP
#define BATTLE_CPP

#include "Battle.h"

Battle::Battle(std::shared_ptr<Creature> creature1, std::shared_ptr<Creature> creature2) {
	this->creature1 = creature1;
	this->creature2 = creature2;
}

void Battle::doTurn(std::shared_ptr<Move> creature1Move, std::shared_ptr<Move> creature2Move) {
	std::unique_ptr<Turn> turn = std::make_unique<Turn>(creature1, creature2, creature1Move, creature2Move);
	while (turn->moreMoments())
	{
		std::shared_ptr<CombatMoment> cm = turn->nextMoment();
		std::shared_ptr<Creature> target = cm->getTargetCreature();
		double targetDef = target->getDefence();
		std::shared_ptr<Creature> source = cm->getSourceCreature();
		double sourceAtk = source->getAttack();
		std::shared_ptr<Move> move = cm->getMove();
		double movePower = move->getPower();
		unsigned int damage = calculateDamage(source->getAttack(), move->getPower(), target->getDefence());
		target->takeDamage(damage);
		double health = target->getCurrentHealth();
		if (health <= 0) {
			turn->clearMoments(*target);
		}
	}
}

unsigned int Battle::calculateDamage(double attack, double power, double defence) const {
	return power * (attack / defence);
}
#endif // BATTLE_CPP