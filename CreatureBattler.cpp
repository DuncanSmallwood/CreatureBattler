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

	shared_ptr<Creature> creature1 = make_shared<Creature>(100, 10, 30, 50, new set<CreatureTypeEnum::CreatureTypeEnum>());
	creature1->setName("ditto");
	shared_ptr<Creature> creature2 = make_shared<Creature>(100, 30, 10, 20, new set<CreatureTypeEnum::CreatureTypeEnum>());
	creature2->setName("bidoof");
	shared_ptr<Battle> battle = make_shared<Battle>(creature1, creature2);

	do {
		cout << *creature1 << endl;
		cout << *creature2 << endl;
		shared_ptr<Move> creature1Move = make_unique<Move>(50,100,MoveTypeEnum::EARTH);
		shared_ptr<Move> creature2Move = make_unique<Move>(50,100,MoveTypeEnum::WATER);
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
