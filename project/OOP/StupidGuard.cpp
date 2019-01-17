#include "StupidGuard.h"
#include "DynamicFactory.h"
#include "Robot.h"
#include "Rock.h"
#include "Fire.h"
#include "Wall.h"

StupidGuard::StupidGuard(sf::Vector2f &pos) : Guards(StupidGuard_type,pos)
{
	//m_moveTimeS = sf::seconds((float)0.5);
}

void StupidGuard::move(const Board & board)
{
	if (m_timeSGuard.getElapsedTime().asSeconds() >= m_moveTimeS.asSeconds())//enter every time guard need to move.
	{
		if (m_timeSGuard.getElapsedTime().asSeconds() >= m_randTime.asSeconds())//enter every time guard need to change direction.
		{
			m_dir = (Direction_t)(rand() % Max_d);
			m_timeSGuard.restart();
		}
		switch (m_dir)
		{
		case Right:
			m_step = { m_speed,  0 };
			break;
		case Down:
			m_step = { 0,  m_speed };
			break;
		case Up:
			m_step = { 0,  -m_speed };
			break;
		case Left:
			m_step = { -m_speed, 0 };
			break;
		case Wait:
			m_step = { 0,0 };
			break;
		default:
			break;
		}
		m_sprite.move(m_step);//TODO check if move is valid in the screen.
	}
}


StupidGuard::~StupidGuard()
{
}
bool StupidGuard::isCollide(const sf::FloatRect & rect) const
{
	if (m_sprite.getGlobalBounds().intersects(rect)) {
		std::cout << "StupidGuard Vs Float rect" << std::endl;
		return true;
	}
	return false;
}
//---------------------------------------------------------
bool StupidGuard::collideHandler(GameObjects & other)
{
	return other.collideHandler(*this);
}
//---------------------------------------------------------
bool StupidGuard::collideHandler(Robot & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "StupidGuard vs Robot" << std::endl;
		return true;
	}
	return false;
}
//---------------------------------------------------------
bool StupidGuard::collideHandler(Rock & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "StupidGuard vs Rock" << std::endl;
		return true;
	}
	return false;
}
//---------------------------------------------------------
bool StupidGuard::collideHandler(Wall & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "StupidGuard vs Wall" << std::endl;
		return true;
	}
	return false;
}
//-----------------------------------------------------------
bool StupidGuard::collideHandler(Fire & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "StupidGuard vs Fire" << std::endl;
		return true;
	}
	return false;
}
//---------------------------------------------------------

bool StupidGuard::m_registered = DynamicFactory::registerit(Stupid_Guard_c, [](sf::Vector2f &pos) -> std::unique_ptr<Guards> { return std::make_unique< StupidGuard>(pos); });