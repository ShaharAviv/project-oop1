#include "DynamicFactory.h"
#include "Robot.h"


DynamicFactory::DynamicFactory()
{
}


DynamicFactory::~DynamicFactory()
{
}

std::unique_ptr<Guards> DynamicFactory::create(const char & name, sf::Vector2f &place)
{
	char tmp = name;
	if (name == Guard_c)
		tmp = (rand() % 20 == 0) ? Smart_Guard_c : Stupid_Guard_c;
	

	auto it = getMap().find(tmp); //looking for cell in map
	if (it == getMap().end()) //if cell does not exist
		return nullptr;
	return it->second(place); //call the function that creates the pointer
}

myDynamicMap & DynamicFactory::getMap()
{
	static myDynamicMap m_map;
	return m_map;
}

bool DynamicFactory::registerit(const char & name, std::unique_ptr<Guards>(*f)(sf::Vector2f &))
{
	getMap().emplace(name, f); //insert into map
	return true;
}
