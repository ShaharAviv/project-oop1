#include "Rock.h"
#include "Robot.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include "Fire.h"
#include "ObjectFactory.h"


Rock::Rock(sf::Vector2f &pos) : UnMoveAble(Rock_type, pos)
{
}


Rock::~Rock()
{
}
bool Rock::isCollide(const sf::FloatRect & rect) const
{
	if (m_sprite.getGlobalBounds().intersects(rect)) {
		std::cout << "Rock Vs Float rect" << std::endl;
		return true;
	}
	return false;
}
//------------------------------------------------------------
bool Rock::collideHandler(GameObjects & other)
{
	return other.collideHandler(*this);
}
//--------------------------------------------------------
bool Rock::collideHandler(Robot & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Rock vs Robot" << std::endl;
		return true;
	}
	return false;
}
//-------------------------------------------------------------
bool Rock::collideHandler(SmartGuard & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Rock vs SmartGuard" << std::endl;
		return true;
	}
	return false;
}
//-----------------------------------------------------------------
bool Rock::collideHandler(StupidGuard & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Rock vs StupidGuard" << std::endl;
		return true;
	}
	return false;
}
//------------------------------------------------------------------
bool Rock::collideHandler(Fire & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Rock vs Fire" << std::endl;
		return true;
	}
	return false;
}
//---------------------------------------------------------
bool Rock::m_registered = ObjectFactory::registerit(Rock_c, [](sf::Vector2f &place) -> std::unique_ptr<UnMoveAble> { return std::make_unique<Rock>(place); });