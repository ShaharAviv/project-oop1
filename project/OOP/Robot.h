#pragma once
#include "MoveAble.h"
#include <functional>

//-------SHAHAR------
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
	void bombsCounterDown() { m_bombs--; }
	int getLeftBombs() const;


	void setDirection(const sf::Event &event);
	void setStep(const sf::Vector2f&) { m_sprite.move(m_step); }

private:
	float m_time;
	bool m_moveHands = false;
	sf::Time m_moveTimer = sf::seconds(0.2f);
	sf::Clock m_timer;
	std::map < sf::Keyboard::Key, std::function<void(void)>> m_moves;//holds direction of the robot.
	unsigned m_score = 0;
	int m_strikes = 3;
	int m_bombs = 20; //count every bomb that the robot used 
};

