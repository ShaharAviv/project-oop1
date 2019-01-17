#include "Menu.h"
#include "PlayGame.h"
#include "Resume.h"
#include "Exit.h"
#include "Help.h"


Menu::Menu()
{
	//m_option.resize(Max_b);
	m_option.push_back((std::make_unique<PlayGame>()));
	m_option.push_back((std::make_unique<Exit>()));
	m_option.push_back((std::make_unique<Resume>()));
	m_option.push_back((std::make_unique<Help>()));
}

void Menu::Play()
{
	//make it global, or at least a member 
	sf::RenderWindow m_window(sf::VideoMode((float)Width, (float)Height), 32u, sf::Style::Close);

	while (m_window.isOpen())
	{
		m_window.clear();

		//Pictures::getInstance().playMenuBackground();
		m_window.draw(m_background);

		for (const auto& option : m_option)
			option->draw(m_window);

		getOptionFromUser(m_window);

		//performAction(action, m_window);

		m_window.display();
	}
}





Menu::~Menu()
{
}
