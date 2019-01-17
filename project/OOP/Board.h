#pragma once
#include "Robot.h"
#include "SmartGuard.h"
#include "StupidGuard.h"
#include "Wall.h"
#include "Door.h"
#include "Rock.h"
#include "Bomb.h"
#include <fstream>
#include <string>

using std::ifstream;
//--------SHAHAR-------
class Board
{
public:
	Board();
	~Board();
	bool readFile(vector<std::unique_ptr<Guards>> &, vector<std::unique_ptr<UnMoveAble>> &staticBoard,
				  std::unique_ptr<Robot>&robot);
	void printBoard(const vector < std::unique_ptr<Bomb>>&, const vector<std::unique_ptr<Guards>> &, const vector<std::unique_ptr<UnMoveAble>> &staticBoard, const std::unique_ptr<Robot>&robot,
		sf::RenderWindow &window);
	sf::Vector2i getBoardSize() const { return {m_row,m_col}; }
	sf::VideoMode getWindowSize();
	sf::Vector2i getCellIndex(const sf::Vector2f& pos);
	void drawGrid(sf::RenderWindow& window);
private:
	ifstream m_level;
	int m_row, m_col, m_amountBombs;
};

