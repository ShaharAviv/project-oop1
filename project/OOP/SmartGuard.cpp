#include "SmartGuard.h"
#include "Board.h"
#include "Keys.h"
#include "Fire.h"
#include "DynamicFactory.h"

SmartGuard::SmartGuard(sf::Vector2f &guardpos) : Guards(SmartGuard_type,guardpos) 
{
}

void SmartGuard::move(const Board & board)
{
	if (m_timeSGuard.getElapsedTime().asSeconds() >= m_moveTimeS.asSeconds())
	{
		moveManhathen(board);
		m_timeSGuard.restart();
	}
}

void SmartGuard::moveManhathen(const Board &board)
{
	double minDistance =  board.getBoardSize().x * board.getBoardSize().y *2; 
	sf::Vector2f minPosition = m_sprite.getPosition();

	checkPosition(m_robot->getPosition(), { (float)m_sprite.getPosition().x + m_speed , (float)m_sprite.getPosition().y} , minDistance, minPosition, board);
	checkPosition(m_robot->getPosition(), { (float)m_sprite.getPosition().x -m_speed, (float)m_sprite.getPosition().y}, minDistance, minPosition, board);
	checkPosition(m_robot->getPosition(), { (float)m_sprite.getPosition().x, (float)m_sprite.getPosition().y -m_speed }, minDistance, minPosition, board);
	checkPosition(m_robot->getPosition(), { (float)m_sprite.getPosition().x, (float)m_sprite.getPosition().y + m_speed }, minDistance, minPosition, board);

	//m_sprite.getPosition = minPosition;
	auto next = minPosition;
	next.x -= m_sprite.getPosition().x;
	next.y -= m_sprite.getPosition().y;

	sf::IntRect tmp(PLAYER_WIDTH * m_stepCount, m_dir * PLAYER_WIDTH, PLAYER_WIDTH, PLAYER_WIDTH);
	m_sprite.setTextureRect(tmp);

	m_sprite.move(next);	
}

double SmartGuard::distance(const sf::Vector2f & v1, const sf::Vector2f & v2)
{
	return std::sqrt(std::pow(abs(v1.x - v2.x), 2)
		+ std::pow(abs(v1.y - v2.y), 2));
}

void SmartGuard::checkPosition(const sf::Vector2f &robotPosition, const sf::Vector2f &nextPosition,
	double &minDistance, sf::Vector2f &minPosition, const Board &board)
{//TODO adding if its available move function
//if (!board.staticCrash(nextPosition, WALL) && !board.staticCrash(nextPosition, ROCK))
	if (distance(robotPosition, nextPosition) < minDistance)
	{
		minDistance = distance(robotPosition, nextPosition);
		minPosition = nextPosition;
	}

}

SmartGuard::~SmartGuard()
{
}

bool SmartGuard::isCollide(const sf::FloatRect & rect) const
{
	if (m_sprite.getGlobalBounds().intersects(rect)) {
		std::cout << "SmartGuard vs Float Rect" << std::endl;
		return true;
	}
	return false;
}

bool SmartGuard::collideHandler(GameObjects & other)
{
	return other.collideHandler(*this);
}

bool SmartGuard::collideHandler(Robot & other)
{
	
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "SmartGuard Vs Robot" << std::endl;
		return true;
	}
	return false;
}

bool SmartGuard::collideHandler(Rock & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "SmartGuard Vs Rock" << std::endl;
		return true;
	}
	return false;
	
}

bool SmartGuard::collideHandler(Wall & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "SmartGuard Vs Wall" << std::endl;
		return true;
	}
	return false;
}

bool SmartGuard::collideHandler(Fire & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "SmartGuard Vs Fire" << std::endl;
		return true;
	}
	return false;
}



bool SmartGuard::m_registered = DynamicFactory::registerit(Smart_Guard_c, [](sf::Vector2f &pos) -> std::unique_ptr<Guards> { return std::make_unique< SmartGuard>( pos ); });