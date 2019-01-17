#include "UnMoveAble.h"

UnMoveAble::UnMoveAble(const Object_t &obj, sf::Vector2f &place) : GameObjects(place)
{
	m_texture = Pictures::getInstance().getTexture(obj);
	m_sprite.setTexture(*m_texture);
}
