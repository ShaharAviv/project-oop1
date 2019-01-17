#include "Bomb.h"
#include "Robot.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include "Fire.h"


Bomb::Bomb(sf::Vector2f &pos) :GameObjects(pos)
{
	m_texture = (Pictures::getInstance().getTexture(Bomb_type));
	m_sprite.setTexture(*m_texture);
	sf::IntRect bomb = { 0, 0 , PIC_SIZE, PIC_LENGTH };
	m_sprite.setTextureRect(bomb);
	m_sprite.setPosition({ pos.x + 5,pos.y + 5 });

	pos.x /= PIC_SIZE;
	pos.y /= PIC_SIZE;

	sf::Vector2f loc;
	for (int i = 0; i < 4; i++)
	{
		m_dir = dirr[i];
		switch (m_dir)
		{
		case Right:
			pos.x++;
			break;
		case Down:
			pos.y++;
			break;
		case Up:
			pos.y--;
			break;
		case Left:
			pos.x--;
			break;
		}
		loc = { pos.x, pos.y };
		m_fire.push_back(std::make_unique<Fire>(loc, m_dir));
	}
}


Bomb::~Bomb()
{
}

bool Bomb::isTimeOver() const
{
	return (m_timer.getElapsedTime().asSeconds() >= bombTime.asSeconds());
}

bool Bomb::timeToClean() const 
{
	//return (m_timer.getElapsedTime().asSeconds() - bombTime > 6);
	//m_fire.erase(std::unique_ptr<Fire>::)
	return false;
}

void Bomb::TimeToExploade(sf::RenderWindow& window)
{
	for (auto& f : m_fire)
		f->draw(window);
}