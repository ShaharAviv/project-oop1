#include "MoveAble.h"

MoveAble::MoveAble(sf::Vector2f &pos) : GameObjects(pos), m_speed(0.2f), m_step({0,0}),m_stepCount(0)
{
}

