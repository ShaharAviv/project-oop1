#include <SFML\Graphics.hpp>
#include "Pictures.h"

//====================class decerations========================================
#pragma once
const int Width = 1074;
const int Height = 604;

// abstarcat class for menu commands-buttons
class Command
{
public:
	Command() {
		const auto mid = sf::Vector2f(Width / 2.f, Height / 2.f);
		sf::Vector2f startPos = { mid.x + 90, mid.y + 20 };
	}
	sf::Sprite getSprite() { return m_sprite; }
	virtual ~Command() = 0 {}
	bool contains(const sf::Vector2f& pos)const { return m_sprite.getGlobalBounds().contains(pos); }
	void doHover(const sf::Vector2f& scale) { m_sprite.setScale(scale); }
	virtual void execute(sf::RenderWindow&) = 0;
	virtual void draw(sf::RenderWindow& window) 
	{
		window.draw(m_sprite);
		window.draw(m_text);
	}

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Text m_text;
	sf::Vector2f startPos;
};

