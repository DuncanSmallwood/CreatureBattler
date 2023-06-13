#ifndef RANDOM_MANAGER_H
#define RANDOM_MANAGER_H

#include <random>

class RandomManager {
private:
	static std::minstd_rand* engine;

private:
	static std::minstd_rand* getEngine();
public:
	static bool d2();
	static int rollDice(int diceSides);
};
#endif // RANDOM_MANAGER_H