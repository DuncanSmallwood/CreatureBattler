#include "BattleBuilder.h"

#include <ostream>

BattleBuilder::BattleBuilder(){
	const std::set<CreatureTypeEnum::CreatureTypeEnum> emptyType;
	// create creature 0
	std::vector<Move> moveSet0(4);
	moveSet0[0] = Move(20, 100,MoveTypeEnum::AIR);
	moveSet0[1] = Move(30, 100, MoveTypeEnum::AIR);
	moveSet0[2] = Move(15, 100, MoveTypeEnum::AIR);
	moveSet0[3] = Move(50, 100, MoveTypeEnum::AIR);
	Creature creature0(200, 10, 30, 50, emptyType, moveSet0);
	creature0.setName("ditto");
	// insert creature 0
	creatures[0L] = creature0;
	
	//create creature 1
	std::vector<Move> moveSet1(4);
	moveSet1[0] = Move(60, 100, MoveTypeEnum::AIR);
	moveSet1[1] = Move(25, 100, MoveTypeEnum::AIR);
	moveSet1[2] = Move(40, 100, MoveTypeEnum::AIR);
	moveSet1[3] = Move(35, 100, MoveTypeEnum::AIR);
	Creature creature1(150, 30, 10, 20, emptyType, moveSet1);
	creature1.setName("bidoof");
	//insert creature 1
	creatures[1L] = creature1;
}

Battle* BattleBuilder::buildBattle(CreateCreatureRequest creature1, CreateCreatureRequest creature2){
	Creature* creatureLhs = new Creature(creatures[creature1.creatureId]);
	if(creatureLhs->getName() != creature1.creatureName)
		std::cout << "(Warning) creature with id (" << creature1.creatureId << ") is named \"" << creatureLhs->getName() << "\" not \"" << creature1.creatureName << "\"" << std::endl;
	Creature* creatureRhs = new Creature(creatures[creature2.creatureId]);
	if(creatureRhs->getName() != creature2.creatureName)
		std::cout << "(Warning) creature with id (" << creature2.creatureId << ") is named \"" << creatureRhs->getName() << "\" not \"" << creature2.creatureName << "\"" << std::endl;
	Battle* battle = new Battle(creatureLhs, creatureRhs);
	return battle;
}
