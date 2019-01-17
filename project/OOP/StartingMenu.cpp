#include "StartingMenu.h"



StartingMenu::StartingMenu() 
{
	m_background.setTexture(*Pictures::getInstance().getTexture(StartingMenu_b));
}


void StartingMenu::getOptionFromUser(sf::RenderWindow &window)
{
	sf::Event event{};
	if (window.pollEvent(event))
	{
		sf::Vector2f  mousePos = { (float)sf::Mouse::getPosition(window).x,(float)sf::Mouse::getPosition(window).y };
		for (int i = 0; i < m_option.size(); i++)
		{
			//m_option[i]->doHover({ 1.f, 1.f });TODO
			if (m_option[i]->contains(mousePos))
			{
				//m_option[i]->doHover({1.3f, 1.3f});TODO
				if (event.type == event.MouseButtonReleased)
				{
					m_option[i]->execute(window);
				}
			}
			
		}
	}
	
}


StartingMenu::~StartingMenu()
{
}
