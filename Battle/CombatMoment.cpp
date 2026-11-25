#include "CombatMoment.h"

CombatMoment::CombatMoment(Move* move, Creature* sourceCreature, Creature* targetCreature) {
	this->move = move;
	this->sourceCreature = sourceCreature;
	this->targetCreature = targetCreature;
}

// CombatMoment::CombatMoment(const CombatMoment& other){
// 	this->move = new Move(*(other.move));
// 	this->sourceCreature = new Creature(*(other.sourceCreature));
// 	this->targetCreature = new Creature(*(other.targetCreature));
// }

CombatMoment::CombatMoment(CombatMoment&& other){
	this->move = other.move;
	other.move = nullptr;
	this->sourceCreature = other.sourceCreature;
	other.sourceCreature = nullptr;
	this->targetCreature = other.targetCreature;
	other.targetCreature = nullptr;
}

Move* CombatMoment::getMove() const{
	return move;
}

Creature* CombatMoment::getSourceCreature() const{
	return sourceCreature;
}

Creature* CombatMoment::getTargetCreature() const{
	return targetCreature;
}

// CombatMoment& CombatMoment::operator=(const CombatMoment& other){
// 	this->move = new Move(*(other.move));
// 	this->sourceCreature = new Creature(*(other.sourceCreature));
// 	this->targetCreature = new Creature(*(other.targetCreature));
// 	return *this;
// }

CombatMoment& CombatMoment::operator=(CombatMoment&& other){
	this->move = other.move;
	other.move = nullptr;
	this->sourceCreature = other.sourceCreature;
	other.sourceCreature = nullptr;
	this->targetCreature = other.targetCreature;
	other.targetCreature = nullptr;

	return *this;
}
