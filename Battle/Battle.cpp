#ifndef BATTLE_CPP
#define BATTLE_CPP

#include "Battle.h"

Battle::Battle(Creature* creature1, Creature* creature2) {
	this->creature1 = creature1;
	this->creature2 = creature2;
}

void Battle::doTurn(Move* creature1Move, Move* creature2Move) {
	Turn* turn = new Turn(creature1, creature2, creature1Move, creature2Move);
	while (turn->moreMoments())
	{
		CombatMoment cm = turn->nextMoment();
		Creature* target = cm.getTargetCreature();
		Creature* source = cm.getSourceCreature();
		Move* move = cm.getMove();
		unsigned int damage = calculateDamage(source->getAttack(), move->getPower(), target->getDefence());
		target->takeDamage(damage);
		double health = target->getCurrentHealth();
		if (health <= 0) {
			turn->clearMoments(target);
		}
		delete move;
	}
	delete turn;
	turn = NULL;
}

unsigned int Battle::calculateDamage(double attack, double power, double defence) const {
	return power * (attack / defence);
}
#endif // BATTLE_CPP