#pragma once
#include "GameObjects.h"
class Fire : public GameObjects
{
public:
	Fire(sf::Vector2f&, const Direction_t&);
	~Fire();
	void draw(sf::RenderWindow&);

	virtual bool isCollide(const sf::FloatRect& rect) const;

	virtual bool collideHandler(GameObjects& other);

	virtual bool collideHandler(Robot &other);
	virtual bool collideHandler(SmartGuard& other);
	virtual bool collideHandler(StupidGuard& other);
	virtual bool collideHandler(Rock& other);
	virtual bool collideHandler(Wall& other);
	virtual bool collideHandler(Fire& other);

private:
	float m_time;
	sf::Clock m_timer;
};

