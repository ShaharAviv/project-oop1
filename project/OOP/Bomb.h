#pragma once
#include "GameObjects.h"


class Bomb : public GameObjects
{
public:
	Bomb(sf::Vector2f &pos);
	~Bomb();
	bool isTimeOver() const;
	bool timeToClean() const;
	void TimeToExploade(sf::RenderWindow& window);

	////TODO collides
	virtual bool isCollide(const sf::FloatRect& rect) const { return false; }

	virtual bool collideHandler(GameObjects& other) { return false; }

	virtual bool collideHandler(Robot &other) { return false; }
	virtual bool collideHandler(SmartGuard& other) { return false; }
	virtual bool collideHandler(StupidGuard& other) { return false; }
	virtual bool collideHandler(Rock& other) { return false; }
	virtual bool collideHandler(Wall& other) { return false; }
	virtual bool collideHandler(Fire& other) { return false; }

		

private:
	sf::Clock m_timer;
	sf::Time bombTime = sf::seconds(0.2f);;
	vector<std::unique_ptr<Fire>> m_fire;
	Direction_t dirr[4] = { Right, Down, Up, Left };
};
	
