#ifndef BATTLE_CPP
#define BATTLE_CPP

#include "Battle.h"


Battle::Battle(const Creature& creature1, const Creature& creature2){
	this->creature1.reset(new Creature(creature1));
	this->creature2.reset(new Creature(creature2));
}


Battle::Battle(Creature* creature1, Creature* creature2)
	:creature1(creature1), creature2(creature2){}

void Battle::doTurn(Move* creature1Move, Move* creature2Move) {
	std::unique_ptr<Turn> turn = std::make_unique<Turn>(creature1.get(), creature2.get(), creature1Move, creature2Move);
	while (turn->moreMoments())
	{
		std::shared_ptr<CombatMoment> cm = turn->nextMoment();
		Creature* target = cm->getTargetCreature();
		double targetDef = target->getDefence();
		Creature* source = cm->getSourceCreature();
		double sourceAtk = source->getAttack();
		Move* move = cm->getMove();
		double movePower = move->getPower();
		unsigned int damage = calculateDamage(source->getAttack(), move->getPower(), target->getDefence());
		target->takeDamage(damage);
		double health = target->getCurrentHealth();
		if (health <= 0) {
			turn->clearMoments(*target);
		}
	}
}

std::pair<Creature, Creature> Battle::viewCreatures(){
	return std::make_pair(*creature1, *creature2);
}

unsigned int Battle::calculateDamage(double attack, double power, double defence) const {
	return power * (attack / defence);
}
#endif // BATTLE_CPP
