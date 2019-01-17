#include "Robot.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include "Wall.h"
#include "Fire.h"
#include "Rock.h"


Robot::Robot(sf::Vector2f &pos) : MoveAble(pos),m_time(0.f)
{
	m_texture = (Pictures::getInstance().getTexture(Robot_type));
	m_sprite.setTexture(*m_texture);
	m_sprite.setOrigin(sf::Vector2f{ PLAYER_WIDTH / 2, PLAYER_WIDTH / 2 });
	//m_sprite.setPosition(sf::Vector2f{   m_startLocation.y* PIC_LENGTH + PIC_SIZE / 2,  m_startLocation.x* PIC_LENGTH + PIC_LENGTH / 2 });

	m_moves.emplace(sf::Keyboard::Right, [&]() { m_dir = Right; m_step = { m_speed,0 }; m_sprite.setScale({ 1,1 }); });
	m_moves.emplace(sf::Keyboard::Left, [&]() { m_dir = Right; m_step = { -m_speed,0 }; m_sprite.setScale({ -1,1 }); });
	m_moves.emplace(sf::Keyboard::Up, [&]() { m_dir = Up; m_step = { 0,-m_speed }; m_sprite.setScale({ 1,1 }); });
	m_moves.emplace(sf::Keyboard::Down, [&]() { m_dir = Down; m_step = { 0,m_speed }; m_sprite.setScale({ 1,1 }); });
}
//---------------------------------------------------------------------------------------
Robot::~Robot()
{
}
//----------------------------------------------------------------------------------
void Robot::move(const Board & board)
{
	if (m_timer.getElapsedTime().asSeconds() >= m_moveTimer.asSeconds() && m_moveHands)
	{
		m_timer.restart();
		m_stepCount++;
	}
	if (m_stepCount >= 3) {
		m_stepCount = 0;
	}

	sf::IntRect tmp(PLAYER_WIDTH * m_stepCount, m_dir * PLAYER_WIDTH, PLAYER_WIDTH, PLAYER_WIDTH);
	m_sprite.setTextureRect(tmp);

	m_sprite.move(m_step);
}

sf::Vector2f Robot::getrobotCenter() const
{	
sf::Vector2f robot ;

	robot.x += PLAYER_WIDTH / 2;
	robot.y += PIC_LENGTH / 2;
	return robot;

}



//-------------------------------------------------------------------
bool Robot::isCollide(const sf::FloatRect & rect) const
{
	sf::FloatRect temp = { rect.left - 1, rect.top - 2, rect.width - 2, rect.height - 2 };
	//in order to check the next move
	sf::FloatRect newRec = { m_sprite.getGlobalBounds().left + m_step.x - 1,
							m_sprite.getGlobalBounds().top + m_step.y, 
							m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height};
	if (newRec.intersects(temp))
	{
		return true;

	}
	return false;
}
//-----------------------------------------------------------
bool Robot::collideHandler(GameObjects & other)
{
	return other.collideHandler(*this);
}
//--------------------------------------------------------
bool Robot::collideHandler(SmartGuard & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Robot vs SmartGuard" << std::endl;
		return true;
	}
	return false;
}
//------------------------------------------------------------
bool Robot::collideHandler(StupidGuard & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Robot vs StupidGuard" << std::endl;
		return true;
	}
	return false;
}
//--------------------------------------------------------------
bool Robot::collideHandler(Wall & other)
{
	m_step = { 0,0 };
	return other.isCollide(m_sprite.getGlobalBounds());
}
//------------------------------------------------------------
bool Robot::collideHandler(Fire & other)
{
	if (other.isCollide(m_sprite.getGlobalBounds())) {
		std::cout << "Robot vs Fire" << std::endl;
		return true;
	}
	return false;
}
//--------------------------------------------------------------
void Robot::setDirection(const sf::Event & event)
{

	/*static int i = 0;
	static Direction_t dir1 = Direction_t::Max_d;
	static Direction_t dir2 = Direction_t::Max_d;
	if (i == 0)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			dir1 = Up;
			break;
		case sf::Keyboard::Down:
			dir1 = Down;
			break;
		case sf::Keyboard::Left:
			dir1 = Left;
			break;
		case sf::Keyboard::Right:
			dir1 = Left;
		default:
			break;
		}
	}
	else
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			dir2 = Up;
			break;
		case sf::Keyboard::Down:
			dir2 = Down;
			break;
		case sf::Keyboard::Left:
			dir2 = Left;
			break;
		case sf::Keyboard::Right:
			dir2 = Left;
		default:
			break;
		}
	}

	if(i<= PIC_SIZE && )*/

	for (auto cell : m_moves)
	{
		if (sf::Keyboard::isKeyPressed(cell.first))
		{
			cell.second();
			m_moveHands = true;
			return;
		}
	}
	m_moveHands = false;
	m_step = { 0,0 };
}


