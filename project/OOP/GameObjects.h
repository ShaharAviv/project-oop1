#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Pictures.h"
#include <iostream>

class Wall;
class Fire;
class Rock;
class SmartGuard;
class StupidGuard;
class Robot;
class Board;
using std::vector;
const int windowWidth = 1280;
const int windowHeight = 1024;
const int PIC_SIZE = 60;
const int PLAYER_WIDTH = 50;
const int PIC_LENGTH = 60;

class GameObjects
{
public:
	virtual ~GameObjects() = 0 {}
	virtual void draw(sf::RenderWindow & window) 
	{ 
		m_sprite.setTexture(*m_texture);
		window.draw(m_sprite);
	}
	GameObjects(sf::Vector2f & pos);
	GameObjects() = default;
	GameObjects &operator=(const GameObjects&) = default;
	sf::Vector2f getPosition()  { return m_sprite.getPosition(); }
	void setPosition(const sf::Vector2f &pos) { m_startLocation = pos; }
	//TODO collides
	virtual bool isCollide(const sf::FloatRect& rect) const = 0;

	virtual bool collideHandler(GameObjects& other) = 0;

	virtual bool collideHandler(Robot &other) = 0;
	virtual bool collideHandler(SmartGuard& other) = 0;
	virtual bool collideHandler(StupidGuard& other) = 0;
	virtual bool collideHandler(Rock& other) = 0;
	virtual bool collideHandler(Wall& other) = 0;
	virtual bool collideHandler(Fire& other) = 0;

protected:
	sf::Vector2f m_startLocation;
	sf::Sprite m_sprite;
	sf::Texture *m_texture = nullptr;
	Direction_t m_dir;
};