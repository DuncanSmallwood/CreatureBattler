#include "CreateCreatureRequest.h"

CreateCreatureRequest::CreateCreatureRequest(unsigned long creatureId, std::vector<unsigned long> moves, std::string creatureName)
	: creatureId(creatureId), moves(moves), creatureName(creatureName)
{}

CreateCreatureRequest::CreateCreatureRequest(unsigned long creatureId, std::initializer_list<unsigned long> moves, std::string creatureName)
	: creatureId(creatureId), moves(moves), creatureName(creatureName)
{}
