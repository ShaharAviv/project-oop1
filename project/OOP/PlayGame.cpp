#include "PlayGame.h"

PlayGame::PlayGame()
{
	m_sprite.setTexture(*Pictures::getInstance().getTexture(StartButton_b));
	m_sprite.setTextureRect(sf::IntRect(0, 0, 222, 60));
	m_sprite.setPosition(startPos.x + 400, startPos.y + 400);
	m_text.setFont(*Pictures::getInstance().getFont());
	m_text.setString("Start");
	m_text.setFillColor(sf::Color::Red);
	m_text.setPosition(startPos.x + 435, startPos.y + 410);
	m_text.setCharacterSize(35);
}
