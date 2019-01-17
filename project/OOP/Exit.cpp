#include "Exit.h"

Exit::Exit()
{
	m_sprite.setTexture(*Pictures::getInstance().getTexture(StartButton_b));
	m_sprite.setTextureRect(sf::IntRect(0, 60, 222, 60));
	m_sprite.setPosition(startPos.x + 400, startPos.y + 470);
	m_text.setFont(*Pictures::getInstance().getFont());
	m_text.setString("Exit");
	m_text.setFillColor(sf::Color::Black);
	m_text.setPosition(startPos.x + 465, startPos.y + 475);
	m_text.setCharacterSize(35);
}
