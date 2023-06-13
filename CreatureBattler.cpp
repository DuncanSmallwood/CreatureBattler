// CreatureBattler.cpp : Defines the entry point for the application.
//

#include "CreatureBattler.h"

using namespace std;

struct test {
	public:
		std::shared_ptr<int> internalInt;

};

int main()
{
	cout << "CREATURE BATTLER TEST" << endl;
	cout << "---------------------" << endl;

	vector<Move> moveSet1(4);
	moveSet1[0] = Move(20, 100,MoveTypeEnum::AIR);
	moveSet1[1] = Move(30, 100, MoveTypeEnum::AIR);
	moveSet1[2] = Move(15, 100, MoveTypeEnum::AIR);
	moveSet1[3] = Move(50, 100, MoveTypeEnum::AIR);
	shared_ptr<Creature> creature1 = make_shared<Creature>(200, 10, 30, 50, new set<CreatureTypeEnum::CreatureTypeEnum>(), moveSet1);
	creature1->setName("ditto");
	vector<Move> moveSet2(4);
	moveSet2[0] = Move(60, 100, MoveTypeEnum::AIR);
	moveSet2[1] = Move(25, 100, MoveTypeEnum::AIR);
	moveSet2[2] = Move(40, 100, MoveTypeEnum::AIR);
	moveSet2[3] = Move(35, 100, MoveTypeEnum::AIR);
	shared_ptr<Creature> creature2 = make_shared<Creature>(150, 30, 10, 20, new set<CreatureTypeEnum::CreatureTypeEnum>(), moveSet2);
	creature2->setName("bidoof");
	shared_ptr<Battle> battle = make_shared<Battle>(creature1, creature2);

	do {
		cout << *creature1 << endl;
		cout << *creature2 << endl;
		shared_ptr<Move> creature1Move = make_shared<Move>(creature1->getMove(RandomManager::rollDice(4)));
		shared_ptr<Move> creature2Move = make_shared<Move>(creature2->getMove(RandomManager::rollDice(4)));
		battle->doTurn(creature1Move, creature2Move);
	} while (creature1->getCurrentHealth() > 0 && creature2->getCurrentHealth() > 0);

	Creature* winner = NULL;
	Creature* loser = NULL;
	if (creature1->getCurrentHealth() > 0 && creature2->getCurrentHealth() <= 0) {
		winner = creature1.get();
		loser = creature2.get();
	}
	else if (creature2->getCurrentHealth() > 0 && creature1->getCurrentHealth() <= 0) {
		winner = creature2.get();
		loser = creature1.get();
	}

	cout << "WINNER!!!!" << *winner << endl;
	cout << "loser...." << *loser << endl;

	return 0;
}
