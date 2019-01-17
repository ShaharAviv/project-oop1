#pragma once
#include "Guards.h"

class StupidGuard : public Guards
{
public:
	StupidGuard(sf::Vector2f &pos);
	virtual void move(const Board &board);
	~StupidGuard();

	virtual bool isCollide(const sf::FloatRect& rect) const;

	virtual bool collideHandler(GameObjects& other);

	virtual bool collideHandler(Robot &other);
	virtual bool collideHandler(SmartGuard& other) { return false; }
	virtual bool collideHandler(StupidGuard& other) { return false; }
	virtual bool collideHandler(Rock& other);
	virtual bool collideHandler(Wall& other);
	virtual bool collideHandler(Fire& other);


private:
	static bool m_registered;
	sf::Time m_randTime = sf::seconds((float)0.5);
};

