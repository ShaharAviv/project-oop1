#include "ObjectFactory.h"

std::unique_ptr<UnMoveAble> ObjectFactory::create(const char & name, sf::Vector2f& place)
{
	auto it = getMap().find(name); //looking for cell in map
	if (it == getMap().end()) //if cell does not exist
		return nullptr;
	return it->second(place); //call the function that creates the pointer
}

myMap & ObjectFactory::getMap()
{
	static myMap m_map;
	return m_map; 
}

bool ObjectFactory::registerit(const char & name, std::unique_ptr<UnMoveAble>(*f)(sf::Vector2f &))
{
	getMap().emplace(name, f); //insert into map
	return true;
}


