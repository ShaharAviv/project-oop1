#include "Wall.h"
#include "Robot.h"
#include "StupidGuard.h"
#include "SmartGuard.h"
#include "Fire.h"
#include "ObjectFactory.h"


Wall::Wall(sf::Vector2f &place) : UnMoveAble(Wall_type, place)
{
}


Wall::~Wall()
{
}

bool Wall::isCollide(const sf::FloatRect & rect) const
{
	if (m_sprite.getGlobalBounds().intersects(rect)) {
		return true;
	}
	return false;
}

bool Wall::collideHandler(GameObjects & other)
{
	return other.collideHandler(*this);
}

bool Wall::collideHandler(Robot & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Wall vs Robot" << std::endl;
		other.collideHandler(*this);
		return true;
	}
	return false;
}

bool Wall::collideHandler(SmartGuard & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Wall vs SmartGuard" << std::endl;
		return true;
	}
	return false;
}

bool Wall::collideHandler(StupidGuard & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Wall vs StupidGuard" << std::endl;
		return true;
	}
	return false;
}

bool Wall::collideHandler(Fire & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Wall vs Fire" << std::endl;
		return true;
	}
	return false;
}

bool Wall::m_registered = ObjectFactory::registerit(Wall_c, [](sf::Vector2f &place) -> std::unique_ptr<UnMoveAble> { return std::make_unique<Wall>(place); });