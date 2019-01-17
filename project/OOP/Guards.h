#pragma once
#include "MoveAble.h"
#include <functional>


class Guards : public MoveAble
{
public:
	Guards(const Object_t& obj, sf::Vector2f &pos);
	virtual ~Guards() = 0{};
	virtual void move(const Board &board) = 0;
	virtual void setRobot(Robot& robot) {};
	//--------------------collision double dispach----------------------------------
protected:	
	sf::Clock m_timeSGuard;
	sf::Time m_moveTimeS = sf::seconds((float)0.0019);

};

