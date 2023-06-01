// CreatureBattler.cpp : Defines the entry point for the application.
//

#include "CreatureBattler.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	Creature* creature = new Creature();
	Creature* deadPointer = creature;
	delete creature;
	delete deadPointer;

	return 0;
}
