#include <iostream>
#include <algorithm>
//#include "..\include\struct_mapping\struct_mapping.h"
#include "Creature.h"

bool Creature::registeredWithStructMapping = false;

Creature::Creature() {
	health = -1;
	currentHealth = 0;
	attack = -1;
	attackStage = 0;
	defence = -1;
	defenceStage = 0;
	speed = -1;
	speedStage = 0;
	type = NULL;
}

Creature::Creature(double health, double attack, double defence, double speed, std::set<CreatureTypeEnum::CreatureTypeEnum>* type) {
	this->health = health;
	this->currentHealth = health;
	this->attack = attack;
	this->attackStage = 0;
	this->defence = defence;
	this->defenceStage = 0;
	this->speed = speed;
	this->speedStage = 0;
	this->type = type;
}

Creature::~Creature() {
	if (type != NULL)
		delete type;
	type = NULL;
}

// TODO: set protections against setting a second time
Creature& Creature::setAttack(double attack) {
	this->attack = attack;
	return *this;
}

Creature& Creature::setDefence(double defence) {
	this->defence = defence;
	return *this;
}

Creature& Creature::setHealth(double health) {
	this->health = health;
	return *this;
}

Creature& Creature::setSpeed(double speed) {
	this->speed = speed;
	return *this;
}


Creature& Creature::setType(std::set<CreatureTypeEnum::CreatureTypeEnum>* type) {
	if (this->type != NULL) {
		delete this->type;
	}
	this->type = type;
	return *this;
}

Creature& Creature::ensureType(CreatureTypeEnum::CreatureTypeEnum type) {
	if (this->type == NULL) {
		this->type = new std::set<CreatureTypeEnum::CreatureTypeEnum>();
	}
	
	if(!isType(type)){
	this->type->insert(type);
	}
	return *this;
}

bool Creature::isType(CreatureTypeEnum::CreatureTypeEnum type) {
	bool isType = false;
	if (this->type != NULL) {
		isType = this->type->find(type) != this->type->end();
	}
	return isType;
}


Creature& Creature::takeDamage(double damage) {
	currentHealth = (currentHealth - damage) > 0 ? currentHealth - damage : 0;
	return *this;
}



double Creature::getAttack() const {
	double stageMultiplier = attackStage >= 0 ? ((2 + attackStage) / 2) : (2 / (2 + attackStage));
	return attack * stageMultiplier;
}

double Creature::getCurrentHealth() const {
	return currentHealth;
}

double Creature::getDefence() const {
	double stageMultiplier = defenceStage >= 0 ? ((2 + defenceStage) / 2) : (2 / (2 + defenceStage));
	return defence * stageMultiplier;
}

double Creature::getHealth() const {
	return health;
}

double Creature::getSpeed() const {
	double stageMultiplier = speedStage >= 0 ? ((2 + speedStage) / 2) : (2 / (2 + speedStage));
	return speed * stageMultiplier;
}



Creature& Creature::increaseStatStage(CreatureStatEnum stat, unsigned int numStages) {
	int newStage;
	switch (stat) {
	case ATTACK: 
		newStage = attackStage + numStages;
		attackStage = newStage > 6 ? 6 : newStage;
		break;
	case DEFENCE:
		newStage = defenceStage + numStages;
		defenceStage = newStage > 6 ? 6 : newStage;
		break;
	case SPEED: 
		newStage = speedStage + numStages;
		attackStage = newStage > 6 ? 6 : newStage;
		break;
	}

	return *this;
}

Creature& Creature::decreaseStatStage(CreatureStatEnum stat, unsigned int numStages) {
	int newStage;
	switch (stat) {
	case ATTACK: 
		newStage = attackStage - numStages;
		attackStage = newStage < -6 ? -6 : newStage;
		break;
	case DEFENCE:
		newStage = defenceStage - numStages;
		defenceStage = newStage < -6 ? -6 : newStage;
		break;
	case SPEED:
		newStage = speedStage - numStages;
		speedStage = newStage > -6 ? -6 : newStage;
		break;
	}

	return *this;
}

bool Creature::operator==(const Creature& other) const{
	if (this == &other) {
		return true;
	}
	if (name != other.name || attack != other.attack || defence != other.defence
		|| health != other.health || speed != other.speed) {
		return false;
	}
	std::set<CreatureTypeEnum::CreatureTypeEnum>::iterator i;
	for (i = type->begin(); i != type->end(); ++i) {
		if (other.type->find(*i) == other.type->end())
			return false;
	}
	for (i = other.type->begin(); i != other.type->end(); ++i) {
		if (type->find(*i) == type->end())
			return false;
	}


	return true;
}

// TODO: decide how to JSON this thing
//std::istream& operator>>(std::istream& i, Creature& creature) {
//	//std::string json;
//	//i >> json;
//	//size_t currPos = json.find('<');
//	//size_t nextPos = json.find('>');
//	//size_t diff = nextPos - currPos;
//	////"Creature <"
//	//std::string currVar = json.substr(currPos, diff);
//	//creature.name = currVar;
//	////">: {Attack: "
//	//creature.attack >> "(" >> creature.attackStage
//	//	>> "), Defence: " >> creature.defence >> "(" >> creature.defenceStage >> "), Health: "
//	//	>> creature.currentHealth >> "/" >> creature.health >> ", Speed: " >> creature.speed >> "(" >> creature.speedStage
//	//	>> ")}";
//	return i;
//}

std::ostream& operator<<(std::ostream& o, Creature& creature) {
	std::ios_base::fmtflags oldFlags = o.flags();
	o << std::showpos << "Creature <" << creature.name << ">: {Attack: " << creature.attack << "(" << creature.attackStage
		<< ")" << ", Defence: " << creature.defence << "(" << creature.defenceStage << ")" << ", Health: "
		<< creature.currentHealth << "/" << creature.health << ", Speed: " << creature.speed << "(" << creature.speedStage
		<< ")}";
	o.flags(oldFlags);
	return o;
}


//void Creature::registerWithStructMapping() {
//	if (!registeredWithStructMapping) {
//		struct_mapping::reg(&Creature::attack, "attack");
//		struct_mapping::reg(&Creature::attackStage, "attackStage");
//		struct_mapping::reg(&Creature::defence, "defence");
//		struct_mapping::reg(&Creature::defenceStage, "defenceStage");
//		struct_mapping::reg(&Creature::currentHealth, "currentHealth");
//		struct_mapping::reg(&Creature::health, "health");
//		struct_mapping::reg(&Creature::speed, "speed");
//		struct_mapping::reg(&Creature::speedStage, "speedStage");
//		struct_mapping::reg(&Creature::type, "type");
//		registeredWithStructMapping = true;
//	}
//}