#pragma once
#include "UnMoveAble.h"
class Rock : public UnMoveAble
{
public:
	Rock(sf::Vector2f &pos);
	~Rock();


	virtual bool isCollide(const sf::FloatRect& rect) const;

	virtual bool collideHandler(GameObjects& other);

	virtual bool collideHandler(Robot &other);
	virtual bool collideHandler(SmartGuard& other);
	virtual bool collideHandler(StupidGuard& other);
	virtual bool collideHandler(Rock& other) { return false; }
	virtual bool collideHandler(Wall& other) { return false; }
	virtual bool collideHandler(Fire& other);


private:
	static bool m_registered;
};

