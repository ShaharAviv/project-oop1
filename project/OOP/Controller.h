#pragma once
#include "Board.h"

//-----SHAHAR-------
class Controller
{
public:
	Controller();
	void run(sf::RenderWindow &m_window);
	~Controller();

private:
	vector<std::unique_ptr<Guards>> m_guards;//hold guards.
	vector<std::unique_ptr<UnMoveAble>>m_staticBoard;//holds wall and rock.
	vector<std::unique_ptr<Bomb>>m_bombs;//holds bombs of the player.
	//vector<std::unique_ptr<Fire>>m_fires;//holds fire of the bomb.

	std::unique_ptr<Robot> m_robot;
	Board *m_board;
	void handleEvents(sf::RenderWindow &m_window,sf::Event &event);
	void collides(sf::RenderWindow&);
	void drawBackGround(sf::RenderWindow &);
	void movePlayers();
	void setBomb();
	sf::Clock m_clock;
	sf::Time m_time;
	void newLevel(sf::RenderWindow &m_window); //loading the next level once you meet the door.
	void print_win();
	void drawScore(sf::RenderWindow& window);

};

