#include "Door.h"
#include "ObjectFactory.h"
#include "Robot.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include "Rock.h"
#include "Fire.h"
#include "Wall.h"

Door::Door(sf::Vector2f &pos) : UnMoveAble(Door_type, pos)
{
}


Door::~Door()
{
}
bool Door::isCollide(const sf::FloatRect & rect) const
{
	if (m_sprite.getGlobalBounds().intersects(rect)) {
		std::cout << "Door Vs Float rect" << std::endl;
		return true;
	}
	return false;
}
//---------------------------------------------------------
bool Door::collideHandler(GameObjects & other)
{
	return other.collideHandler(*this);
}
//----------------------------------------------------------
bool Door::collideHandler(Robot & other)
{
	if (other.collideHandler(*this)) {
		std::cout << "Door vs Robot" << std::endl;
		return true;
	}
	return false;
}
//------------------------------------------------------------
bool Door::collideHandler(SmartGuard & other)
{
	if (other.collideHandler(*this)) {
		std::cout << "Door vs SmartGuard" << std::endl;
		return true;
	}
	return false;
}
//----------------------------------------------------------
bool Door::collideHandler(StupidGuard & other)
{
	if (other.collideHandler(*this)) {
		std::cout << "Door vs StupidGuard" << std::endl;
		return true;
	}
	return false;
}
//----------------------------------------------------------------
bool Door::collideHandler(Rock & other)
{
	return false;
}
//----------------------------------------------------------
bool Door::collideHandler(Wall & other)
{
	return false;
}
//----------------------------------------------------------
bool Door::collideHandler(Fire & other)
{
	if (other.collideHandler(*this)) {
		std::cout << "Door vs Fire" << std::endl;
		return true;
	}
	return false;
}
//-----------------------------------------------------------
bool Door::m_registered = ObjectFactory::registerit(Door_c, [](sf::Vector2f &pos) -> std::unique_ptr<UnMoveAble> { return std::make_unique<Door>(pos); });