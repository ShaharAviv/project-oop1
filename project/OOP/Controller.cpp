#include "Controller.h"
#include "Bomb.h"

Controller::Controller() : m_board(new Board())
{
}
//--------------------------------------------------------------------
void Controller::run(sf::RenderWindow &m_window)
{

	m_board->readFile(m_guards, m_staticBoard, m_robot);
	m_window.create(m_board->getWindowSize(), 32u, sf::Style::Close);
	m_window.display();
	
	sf::Event event{};
	while (m_window.isOpen())
	{
		if (Door::collideHandler(m_robot))
		{
			newLevel(m_window);
			continue;
		}

		m_time = m_clock.getElapsedTime();
		m_window.clear();
		handleEvents(m_window,event);
		drawBackGround(m_window);
		m_board->drawGrid(m_window);
		m_robot->setDirection(event);
		collides(m_window);// check collision
		movePlayers();
		for (const auto &bomb : m_bombs)
			bomb->draw(m_window);
	
		for (auto& i : m_bombs)
		{
			if (i->isTimeOver()) 
			{
				i->TimeToExploade(m_window);
				//>timeToClean();
				//release();
			}
		}

		m_board->printBoard(m_bombs, m_guards, m_staticBoard, m_robot, m_window);
		m_window.display();

	}//TODO make a move and check for collision. maybe hold an integer to know if the move is ok and than update.
	//TODO orginaize the controller.
}

//----------------------------------------------------------------------

Controller::~Controller()
{
}

void Controller::handleEvents(sf::RenderWindow &m_window, sf::Event &event)
{
	if (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_window.close();
				break;
			case sf::Keyboard::Space:
				setBomb();
				break;
			}
			break;
		}
	}
}
void Controller::collides(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_staticBoard.size(); i++)
	{
		m_robot->collideHandler(*m_staticBoard[i]);
		
		if(m_robot->collideHandler())
	}
	for (auto& enemy : m_guards)
	{
		enemy->collideHandler(*m_robot);
	}

}
//-----------------------------------------------------------
void Controller::drawBackGround(sf::RenderWindow &m_window)
{
	sf::Sprite b(*Pictures::getInstance().getBack());
	m_window.draw(b);
}
//-----------------------------------------------------------
void Controller::movePlayers()
{
	m_robot->move(*m_board);
	for (auto& temp : m_guards)
		temp->move(*m_board);
}

void Controller::setBomb()
{
	sf::Vector2f pos;
	pos = m_robot->getPosition();
	
	auto cell = m_board->getCellIndex(pos); //because when we set the bomb it should be here.
	pos.x = PIC_SIZE * cell.x;
	pos.y = PIC_SIZE * cell.y;
	
	std::cout << "pos:"<< pos.x << "," << pos.y << std::endl;
	std::cout << "cell:"<< cell.x << "," << cell.y << std::endl;
	//to not put a bomb on top of another
	for (size_t i = 0; i < m_bombs.size(); i++)
	{
		if (m_bombs.at(i)->getPosition() == (m_robot->getPosition()))
		{
			return;
		}
	}
 	std::unique_ptr<Bomb> bomb(std::make_unique<Bomb>(pos));
	m_bombs.push_back(std::move(bomb));
}

void Controller::newLevel(sf::RenderWindow &m_window) //loading the next level once you meet the door.
{
	//m_robot.setScore(m_score);
	//m_bombs.clear();
	m_board->readFile(m_guards, m_staticBoard, m_robot);
	//m_win = false;
	m_board->printBoard(m_bombs ,m_guards, m_staticBoard, m_robot, m_window);
}