#pragma once
#include "UnMoveAble.h"
class Wall : public UnMoveAble
{
public:
	Wall(sf::Vector2f &place);
	~Wall();
	virtual bool isCollide(const sf::FloatRect& rect) const;

	virtual bool collideHandler(GameObjects& other);

	virtual bool collideHandler(Robot &other);
	virtual bool collideHandler(SmartGuard& other);
	virtual bool collideHandler(StupidGuard& other);
	virtual bool collideHandler(Rock& other) { return false; }
	virtual bool collideHandler(Wall& other) { return false; }
	virtual bool collideHandler(Fire& other);

private:
	//static so it registers to map only once
	static bool m_registered;
	
};

