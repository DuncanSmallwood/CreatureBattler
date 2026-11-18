#ifndef CREATE_CREATURE_REQUEST_H
#define CREATE_CREATURE_REQUEST_H

#include <vector>
#include <string>

class CreateCreatureRequest{
	public:
		unsigned long creatureId;
		std::vector<unsigned long> moves;
		std::string creatureName; // exclusivly for confirming correct creature
	public:
		CreateCreatureRequest(unsigned long creatureId, std::vector<unsigned long> moves, std::string creatureName = "");
		CreateCreatureRequest(unsigned long creatureId, std::initializer_list<unsigned long> moves, std::string creatureName = "");
};

#endif // CREATE_CREATURE_REQUEST_H
