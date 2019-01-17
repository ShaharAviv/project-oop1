#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Keys.h"
//------SHAHAR-------
//---------------------------Singelton----------------------------------//
using std::vector;
using std::string;

class Pictures
{
public:
	sf::Texture * getBack() { return &m_back; }
	sf::Texture * getTexture(const Object_t & index);//texture of every object in the game.
	sf::Texture * getTexture(const Photo_t & index);//texture of photos in the game.
	sf::Font * getFont();
	//void playMenuBackground() { m_sound.play(); }
	//void stopMenuBackground() { m_sound.stop(); }
	static Pictures& getInstance();

private:
	Pictures();
	Pictures(const Pictures&) = delete;
	Pictures& operator= (const Pictures&) = delete;
	vector<sf::Texture>m_objects;
	vector<sf::Texture>m_photos;
	sf::Texture m_back;
	sf::Font m_font;
	//sf::Sound m_sound;
	//sf::SoundBuffer m_sound_buffer;
};