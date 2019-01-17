#include "GameObjects.h"

GameObjects::GameObjects(sf::Vector2f &pos) : m_startLocation(pos), m_dir(Up)
{
	m_sprite.setPosition({m_startLocation.y * PIC_SIZE, m_startLocation.x * PIC_SIZE});
}
