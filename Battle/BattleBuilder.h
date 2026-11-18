#ifndef BATTLE_BUILDER_H
#define BATTLE_BUILDER_H

#include <map>
#include <memory>

#include "Battle.h"
#include "../CreatureModel/Creature.h"
#include "../Request-Response/CreateCreatureRequest.h"

class BattleBuilder {
	std::map<unsigned long, Creature> creatures;
	public:
		BattleBuilder();
		Battle* buildBattle(CreateCreatureRequest creature1, CreateCreatureRequest creature2);
};

#endif // BATTLE_BUILDER_H
