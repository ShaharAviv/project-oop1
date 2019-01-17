#include "Controller.h"
#include "Bomb.h"

Controller::Controller() : m_board(new Board())
{
}
//-----------SHAHAR---------------------------------------------------------
void Controller::run(sf::RenderWindow &m_window)
{

	if (!m_board->readFile(m_guards, m_staticBoard, m_robot))
		print_win();
	m_window.create(m_board->getWindowSize(), 32u, sf::Style::Close);
	m_window.display();
	
	sf::Event event{};
	while (m_window.isOpen())
	{

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
		drawScore(m_window);

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
		if (m_robot->collideHandler(*m_staticBoard[i]))
		{
			if (typeid(*m_staticBoard[i]) == typeid(Door))
			{
				newLevel(window);
			}
		}
		
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
//--------------SHAHAR-----------------------
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
	for (auto & bomb :m_bombs)
	{
		auto bombcell = m_board->getCellIndex(bomb->getPosition());
		if (bombcell== cell)
		{
			return;
		}
	}
 	std::unique_ptr<Bomb> bomb(std::make_unique<Bomb>(pos));
	m_bombs.push_back(std::move(bomb));
	m_robot->bombsCounterDown();
}
//------------SHAHAR---------------------------
void Controller::newLevel(sf::RenderWindow &m_window) //loading the next level once you meet the door.
{
	std::cout << "new level";
	//m_robot.setScore(m_score);
	m_bombs.clear();
	m_guards.clear();
	m_staticBoard.clear();
	if(!m_board->readFile(m_guards, m_staticBoard, m_robot))
		//win screen
	m_board->printBoard(m_bombs, m_guards, m_staticBoard, m_robot, m_window);
}
//------------SHAHAR--------------------S
void Controller::print_win()
{
	sf::Texture win_texture;
	win_texture.loadFromFile("Images/win_image.png");
	sf::Sprite win_sprite;
	win_sprite.setTexture(win_texture);
}

//----------------SHAHAR---------------------------
void Controller::drawScore(sf::RenderWindow & window) //TODO make inside functions
{
	sf::Text score_t;
	score_t.setFont(*Pictures::getInstance().getFont());
	score_t.setString("Robot Score");
	score_t.setFillColor(sf::Color::Green);
	score_t.setPosition(25, 910);
	score_t.setCharacterSize(20);
	score_t.setOutlineColor(sf::Color::Red);
	window.draw(score_t);

//----------


	sf::Text life_t;
	life_t.setFont(*Pictures::getInstance().getFont());
	life_t.setString("Life");
	life_t.setFillColor(sf::Color::Green);
	life_t.setPosition(25, 935);
	life_t.setCharacterSize(20);
	life_t.setOutlineColor(sf::Color::Red);
	window.draw(life_t);
//-----------

	sf::Text Left_bombs_t;
	Left_bombs_t.setFont(*Pictures::getInstance().getFont());
	Left_bombs_t.setString("Left bombs");
	Left_bombs_t.setFillColor(sf::Color::Green);
	Left_bombs_t.setPosition(25, 960);
	Left_bombs_t.setCharacterSize(20);
	Left_bombs_t.setOutlineColor(sf::Color::Red);
	window.draw(Left_bombs_t);

	sf::Text score_n;
	score_n.setFont(*Pictures::getInstance().getFont());
	score_n.setString(std::to_string(m_robot->getLeftBombs()));
	score_n.setFillColor(sf::Color::Red);
	score_n.setPosition(250, 960);
	score_n.setCharacterSize(20);
	score_n.setOutlineColor(sf::Color::Red);
	window.draw(score_n);
}