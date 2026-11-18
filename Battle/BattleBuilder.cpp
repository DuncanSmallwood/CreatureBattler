#include "BattleBuilder.h"

#include <ostream>

BattleBuilder::BattleBuilder(){
	// create creature 0
	std::vector<Move> moveSet0(4);
	moveSet0[0] = Move(20, 100,MoveTypeEnum::AIR);
	moveSet0[1] = Move(30, 100, MoveTypeEnum::AIR);
	moveSet0[2] = Move(15, 100, MoveTypeEnum::AIR);
	moveSet0[3] = Move(50, 100, MoveTypeEnum::AIR);
	Creature creature0(200, 10, 30, 50, new std::set<CreatureTypeEnum::CreatureTypeEnum>(), moveSet0);
	creature0.setName("ditto");
	std::cout << "(debug) creature0 created" << std::endl;
	// insert creature 0
	creatures[0L] = creature0;
	std::cout << "(debug) creature0 inserted" << std::endl;
	
	//create creature 1
	std::vector<Move> moveSet1(4);
	moveSet1[0] = Move(60, 100, MoveTypeEnum::AIR);
	moveSet1[1] = Move(25, 100, MoveTypeEnum::AIR);
	moveSet1[2] = Move(40, 100, MoveTypeEnum::AIR);
	moveSet1[3] = Move(35, 100, MoveTypeEnum::AIR);
	Creature creature1(150, 30, 10, 20, new std::set<CreatureTypeEnum::CreatureTypeEnum>(), moveSet1);
	creature1.setName("bidoof");
	std::cout << "(debug) creature1 created" << std::endl;
	//insert creature 1
	creatures[1L] = creature1;
	std::cout << "(debug) creature1 inserted" << std::endl;
}

Battle* BattleBuilder::buildBattle(CreateCreatureRequest creature1, CreateCreatureRequest creature2){
	Creature creatureLhs = creatures[creature1.creatureId];
	if(creatureLhs.getName() != creature1.creatureName)
		std::cout << "(Warning) creature with id (" << creature1.creatureId << ") is named \"" << creatureLhs << "\" not \"" << creature1.creatureName << "\"" << std::endl;
	Creature creatureRhs = creatures[creature2.creatureId];
	if(creatureRhs.getName() != creature2.creatureName)
		std::cout << "(Warning) creature with id (" << creature2.creatureId << ") is named \"" << creatureRhs << "\" not \"" << creature2.creatureName << "\"" << std::endl;
	Battle* battle = new Battle(creatureLhs, creatureRhs);
	std::cout << "(debug) battle created" << std::endl;
	return battle;
}
