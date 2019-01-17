#pragma once
#include "Guards.h"
#include "Robot.h"


class SmartGuard : public Guards
{
public:
	SmartGuard(sf::Vector2f &pos);
	virtual void move(const Board &board);
	~SmartGuard();

	virtual bool isCollide(const sf::FloatRect& rect) const;

	virtual bool collideHandler(GameObjects& other);

	virtual bool collideHandler(Robot &other);
	virtual bool collideHandler(SmartGuard& other) { return false; }
	virtual bool collideHandler(StupidGuard& other) { return false; }
	virtual bool collideHandler(Rock& other);
	virtual bool collideHandler(Wall& other);
	virtual bool collideHandler(Fire& other);


	void setRobot(Robot& robot) override { m_robot = &robot; }


private:
	void checkPosition(const sf::Vector2f &playerPosition, const sf::Vector2f &nextPosition,
	double &minDistance, sf::Vector2f &minPosition, const Board & board);
	void moveManhathen(const Board &board);
	double distance(const sf::Vector2f& v1, const sf::Vector2f& v2);
	static bool m_registered;
	Robot* m_robot;

};

