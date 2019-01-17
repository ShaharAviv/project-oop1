#pragma once
#include "GameObjects.h"
#include "ObjectFactory.h"

class MoveAble : public GameObjects
{
public:
	MoveAble(sf::Vector2f &pos);
	MoveAble() = delete;
	virtual ~MoveAble() = 0 {};
	//void setPosition(const sf::Vector2f place) { m_location = place; }
	virtual void move(const Board &board) = 0 ;
	//---------------------------------------
	/*virtual void collideHandler(GameObjects& other) = 0;

	virtual void collideHandler(Robot &other) = 0;
	virtual void collideHandler(Guards& other) = 0;
	virtual void collideHandler(Rock& other) = 0;
	virtual void collideHandler(Wall& other) = 0;*/
  
protected:
	float m_speed;
	int m_stepCount;
	sf::Vector2f m_step;
	int m_move;
	
};

