#include "Fire.h"

Fire::Fire(sf::Vector2f &bombPos, const Direction_t& dir)
{
	m_dir = dir;
	m_texture = (Pictures::getInstance().getTexture(Boom_type));
	m_sprite.setTexture(*m_texture);
	sf::IntRect tmp(0, m_dir * PIC_SIZE, PIC_SIZE, PIC_SIZE);
	m_sprite.setTextureRect(tmp);
	m_sprite.setPosition(bombPos.x, bombPos.y);
}

Fire::~Fire()
{
}

void Fire::draw(sf::RenderWindow &window)
{
	//sf::IntRect fire = { 0, 0 , PIC_SIZE, PIC_LENGTH };
	window.draw(m_sprite);
}

bool Fire::isCollide(const sf::FloatRect & rect) const
{
	return false;
}

bool Fire::collideHandler(GameObjects & other)
{
	return false;
}

bool Fire::collideHandler(Robot & other)
{
	return false;
}

bool Fire::collideHandler(SmartGuard & other)
{
	return false;
}

bool Fire::collideHandler(StupidGuard & other)
{
	return false;
}

bool Fire::collideHandler(Rock & other)
{
	return false;
}

bool Fire::collideHandler(Wall & other)
{
	return false;
}

bool Fire::collideHandler(Fire & other)
{
	return false;
}
