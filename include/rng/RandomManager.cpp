#ifndef RANDOM_MANAGER_CPP
#define RANDOM_MANAGER_CPP

#include <random>
#include "RandomManager.h"

std::minstd_rand* RandomManager::engine = NULL;

std::minstd_rand* RandomManager::getEngine() {
	if (engine == NULL) {
		std::random_device rd;
		engine = new std::minstd_rand(rd());
	}
	return engine;
}

bool RandomManager::d2() {
	std::minstd_rand* rng = getEngine();
	std::uniform_int_distribution<int> dist(0,1);
	return dist(*rng) == 0;
}

int RandomManager::rollDice(int diceSides) {
	std::minstd_rand* rng = getEngine();
	std::uniform_int_distribution<int> dist(0, diceSides - 1);
	return dist(*rng);
}
#endif // RANDOM_MANAGER_CPP