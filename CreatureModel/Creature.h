#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <set>
#include <vector>

#include "Enum/CreatureStatEnum.cpp"
#include "Enum/CreatureTypeEnum.cpp"
#include "Move.h"

class Creature {
private:
	std::string name;
	double attack;
	double defence;
	double health;
	double speed;

	std::set<CreatureTypeEnum::CreatureTypeEnum>* type;

	std::vector<Move> moves;

	int attackStage;
	double currentHealth;
	int defenceStage;
	int speedStage;

public:
	Creature();
	Creature(double health, double attack, double defence, double speed, std::set<CreatureTypeEnum::CreatureTypeEnum>* type, std::vector<Move> moves);
	~Creature();

	Creature& setAttack(double attack);
	Creature& setDefence(double defence);
	Creature& setHealth(double health);
	Creature& setSpeed(double speed);
	Creature& setName(std::string name);

	Creature& setType(std::set<CreatureTypeEnum::CreatureTypeEnum>* type);
	Creature& ensureType(CreatureTypeEnum::CreatureTypeEnum type);
	bool isType(CreatureTypeEnum::CreatureTypeEnum type);

	Creature& replaceOrAddMove(const Move& newMove, int moveToReplace);

	Creature& takeDamage(double damage);

	virtual double getAttack() const;
	double getCurrentHealth() const;
	virtual double getDefence() const;
	virtual double getHealth() const;
	virtual double getSpeed() const;
	std::vector<Move> getMoves();
	const Move& getMove(int moveIndex);

	virtual Creature& increaseStatStage(CreatureStatEnum stat, unsigned int numStages);
	virtual Creature& decreaseStatStage(CreatureStatEnum stat, unsigned int numStages);

	bool operator==(const Creature& other) const;

	// TODO: is this even nessesary
	//friend std::istream& operator>>(std::istream& i, Creature& creature);

	friend std::ostream& operator<<(std::ostream& o, Creature& creature);

private:
	static bool registeredWithStructMapping;
	//static void registerWithStructMapping();
};
#endif