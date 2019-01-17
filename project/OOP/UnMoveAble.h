#pragma once
#include "GameObjects.h"
class UnMoveAble : public GameObjects
{
public:
	UnMoveAble(const Object_t &obj, sf::Vector2f &place);
	virtual ~UnMoveAble() = 0 {};
	virtual void draw(sf::RenderWindow &window) { window.draw(m_sprite); }
protected:

};

