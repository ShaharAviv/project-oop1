#include "Guards.h"



Guards::Guards(const Object_t& obj ,sf::Vector2f &pos) : MoveAble(pos)
{
	m_texture = (Pictures::getInstance().getTexture(SmartGuard_type));
	m_dir = Right;
	m_sprite.setTexture(*m_texture);
	m_sprite.setOrigin(sf::Vector2f{ PLAYER_WIDTH / 2, PLAYER_WIDTH / 2 });
}