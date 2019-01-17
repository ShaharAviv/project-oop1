#pragma once
#include "UnMoveAble.h"


//typedef std::map<char, MoveAble*(*)(sf::Vector2f&)> Move;
typedef std::map<char, std::unique_ptr<UnMoveAble>(*)(sf::Vector2f&)> myMap;
//typedef std::map<char, UnMoveAble*(*)(sf::Vector2f&)> UnMove;
class ObjectFactory
{
public:
	ObjectFactory() {};
	~ObjectFactory() {};
	//static MoveAble* create(const char& name, sf::Vector2f&); //gets the key and returns a pointer to new object
	static std::unique_ptr<UnMoveAble> create(const char& name, sf::Vector2f&); //gets the key and returns a pointer to new object
	//static bool registerit(const char& name, MoveAble*(*)(sf::Vector2f&));  //each object will register itself to map 
	static bool registerit(const char& name, std::unique_ptr<UnMoveAble>(*)(sf::Vector2f&));  //each object will register itself to map 
	//only this class can get map
private:
	//static Move& getMovableMap();
	static myMap& getMap();
};

//-------------------------------------------------------------------------------------------------
