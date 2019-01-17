#pragma once
#include "Menu.h"

class StartingMenu : public Menu
{
public:
	StartingMenu();

	virtual void getOptionFromUser(sf::RenderWindow&);
	~StartingMenu();
};

