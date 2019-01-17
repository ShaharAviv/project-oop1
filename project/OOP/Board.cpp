#include "Board.h"
#include <iostream>
#include "DynamicFactory.h"

//-------SHAHAR-----

Board::Board() : m_level("board.bomb.txt")//TODO name of file
{
	if (!m_level.is_open())
	{
		std::cout << "Problem opening file\n";
		exit(EXIT_FAILURE);
	}
}


Board::~Board()
{
	m_level.close();
}

bool Board::readFile(vector<std::unique_ptr<Guards>> &guards, vector<std::unique_ptr<UnMoveAble>> &staticBoard,
					std::unique_ptr<Robot> &robot)
{
	if (m_level.eof())
	{
		return false;
	}

	//sf::Clock m_time;
	m_level >> m_row;
	m_level >> m_col;
	//m_level >> m_amountBombs;
	//m_level >> m_time;
	
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			char c = m_level.get();

			if (c == '\n') {
				j--;
				continue;
			}

			sf::Vector2f pos = { (float)i,(float)j };
				
			//trying to get pointer of unmoveable object
			auto ptr = ObjectFactory::create(c, pos);
			if (ptr != nullptr) { //if it is not nullptr it is unmoveable
				staticBoard.push_back(std::move(ptr));	
				continue;
				}
			auto ptr2 = DynamicFactory::create(c, pos);
			if (ptr2 != nullptr) { //if it is not nullptr it is unmoveable
				guards.push_back(std::move(ptr2));
				continue;
			}

			else if(c == Robot_c)
			{
				robot = std::make_unique<Robot>(pos);
			}
		}
	}

	for (auto& guard : guards)
	{
		guard->setRobot(*robot);
	}

	return true;
}
//---------------------------SHAHAR-----------------------
void Board::printBoard(const vector <std::unique_ptr<Bomb>>& bombs, const vector<std::unique_ptr<Guards>> &guards, 
	const vector<std::unique_ptr<UnMoveAble>> &staticBoard, const std::unique_ptr<Robot>&robot,  sf::RenderWindow &window)
{
	/*for (const auto &bomb : bombs)
		bomb->draw(window);*/
	for (const auto &i : guards)
		i->draw(window);
	for (const auto &i : staticBoard)
		i->draw(window);
	robot->draw(window);

	//drawScore(window);
}

sf::VideoMode Board::getWindowSize()
{
	return sf::VideoMode(m_col * PIC_SIZE,
		m_row * PIC_SIZE+100);
}

sf::Vector2i Board::getCellIndex(const sf::Vector2f & pos)
{
	sf::Vector2i cell;
	cell.x = pos.x - ((int)pos.x % PIC_SIZE);
	cell.y = pos.y - ((int)pos.y % PIC_LENGTH);

	cell.x /= PIC_SIZE;
	cell.y /= PIC_LENGTH;

	std::cout << "Recieved:" << pos.x << " " << pos.y << std::endl;
	std::cout << "Transform:" << cell.x << " " << cell.y << std::endl;

	return cell;
}
void Board::drawGrid(sf::RenderWindow & window) {
	sf::RectangleShape m_c;
	sf::RectangleShape m_r;

	m_c.setSize(sf::Vector2f(1, float(m_row*PIC_SIZE)));
	m_r.setSize(sf::Vector2f(float((m_col)*PIC_SIZE - PIC_SIZE), 1));

	for (int i = 0; i <= m_row; i++)
	{
		m_r.setPosition(PIC_SIZE, i*PIC_SIZE);
		window.draw(m_r);
	}
	for (int i = 0; i < m_col; i++)
	{
		m_c.setPosition(PIC_SIZE*i + PIC_SIZE, 0);
		window.draw(m_c);
	}

}

