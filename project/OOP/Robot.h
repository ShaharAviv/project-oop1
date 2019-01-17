#pragma once
#include "MoveAble.h"
#include <functional>

class Robot : public MoveAble
{
public:
	Robot(sf::Vector2f &pos);
	virtual ~Robot();
	virtual void move(const Board &board) override;
	sf::Vector2f getrobotCenter()const;
	//----------------Double Dispatch--------------------
	virtual bool isCollide(const sf::FloatRect& rect) const;
	virtual bool collideHandler(GameObjects& other);
	virtual bool collideHandler(Robot &other) { return false; }
	virtual bool collideHandler(SmartGuard& other);
	virtual bool collideHandler(StupidGuard& other);
	virtual bool collideHandler(Rock& other) { return false; }
	virtual bool collideHandler(Wall& other);
	virtual bool collideHandler(Fire& other);


	void setDirection(const sf::Event &event);
	void setStep(const sf::Vector2f&) { m_sprite.move(m_step); }

private:
	unsigned m_life;
	float m_time;
	unsigned m_score;
	bool m_moveHands = false;
	sf::Time m_moveTimer = sf::seconds(0.2f);
	sf::Clock m_timer;
	std::map < sf::Keyboard::Key, std::function<void(void)>> m_moves;//holds direction of the robot.
};

