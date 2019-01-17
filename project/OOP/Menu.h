#include <memory>
#include <string>
#include <iostream>
#include "Command.h"

#pragma once
using button = std::pair<sf::Sprite, sf::Text>;
class Menu
{
public:
	Menu();
	void Play();

	//virtual function because every menu have user choice.
	virtual void getOptionFromUser(sf::RenderWindow&) = 0;


	virtual ~Menu() = 0;

protected:
	vector<std::unique_ptr<Command>> m_option;
	sf::Sprite m_background;
};

