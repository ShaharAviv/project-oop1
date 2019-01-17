#pragma once
#include "Guards.h"
typedef std::map<char, std::unique_ptr<Guards>(*)(sf::Vector2f&)> myDynamicMap;
class DynamicFactory
{
public:
	DynamicFactory();
	~DynamicFactory();

	//typedef std::map<char, MoveAble*(*)(sf::Vector2f&)> Move;

	//typedef std::map<char, UnMoveAble*(*)(sf::Vector2f&)> UnMove;

		//static MoveAble* create(const char& name, sf::Vector2f&); //gets the key and returns a pointer to new object
	static std::unique_ptr<Guards> create(const char& name, sf::Vector2f&); //gets the key and returns a pointer to new object
	//static bool registerit(const char& name, MoveAble*(*)(sf::Vector2f&));  //each object will register itself to map 
	static bool registerit(const char& name, std::unique_ptr<Guards>(*)(sf::Vector2f&));  //each object will register itself to map 
	//only this class can get map
private:
	//static Move& getMovableMap();
	static myDynamicMap& getMap();
};


