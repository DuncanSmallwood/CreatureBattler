// CreatureBattler.cpp : Defines the entry point for the application.
//

#include "CreatureBattler.h"

using namespace std;

int main()
{
	cout << "CREATURE BATTLER TEST" << endl;
	cout << "---------------------" << endl;

	BattleBuilder* battleBuilder = new BattleBuilder;
	CreateCreatureRequest creature1Request(0L, {0L, 0L, 0L, 0L}, "ditto");
	CreateCreatureRequest creature2Request(1L, {0L, 0L, 0L, 0L}, "bidoof");
	Battle* battle = battleBuilder->buildBattle(creature1Request, creature2Request);

	std::pair<Creature, Creature> participants;
	do {
		participants = battle->viewCreatures();
		cout << participants.first << endl;
		cout << participants.second << endl;
		Move* creature1Move = new Move(participants.first.getMove(RandomManager::rollDice(4)));
		Move* creature2Move = new Move(participants.second.getMove(RandomManager::rollDice(4)));
		battle->doTurn(creature1Move, creature2Move);
		delete creature1Move;
		delete creature2Move;
	} while (participants.first.getCurrentHealth() > 0 && participants.second.getCurrentHealth() > 0);

	Creature* winner = NULL;
	Creature* loser = NULL;
	if (participants.first.getCurrentHealth() > 0 && participants.second.getCurrentHealth() <= 0) {
		winner = &participants.first;
		loser = &participants.second;
	}
	else if (participants.second.getCurrentHealth() > 0 && participants.first.getCurrentHealth() <= 0) {
		winner = &participants.second;
		loser = &participants.first;
	}

	cout << "WINNER!!!!" << *winner << endl;
	cout << "loser...." << *loser << endl;
	
	if(battle){
		delete battle;
		battle = nullptr;
	}

	if(battleBuilder){
		delete battleBuilder;
		battleBuilder = nullptr;
	}

	return 0;
}
