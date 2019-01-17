#include "Pictures.h"

//-------SHAHAR--------
Pictures::Pictures()
{
	m_objects.resize(Max);
	const string sname = "Images/image";
	const string bname = "Images/photo";
	const string picType = ".png";
	string name;

	for (int i = 0; i < Max; i++)
	{
		name = sname + std::to_string(i) + picType;
		m_objects[i].loadFromFile(name);
	}
	m_back.loadFromFile("Images/background.png");

	m_photos.resize(Max_b);
	for (int i = 0; i < Max_b; i++)
	{
		name = bname + std::to_string(i) + picType;
		m_photos[i].loadFromFile(name);
	}

	m_font.loadFromFile("font/typedef.ttf");

	//m_sound_buffer.loadFromFile("Music/backgroundMusicMenu.wav");
	//m_sound.setBuffer(m_sound_buffer);
}


sf::Texture * Pictures::getTexture(const Object_t & index)
{
	return &m_objects.at(index);
}

sf::Texture * Pictures::getTexture(const Photo_t & index)
{
	return &m_photos.at(index);
}

sf::Font * Pictures::getFont()
{
	return &m_font;
}

Pictures & Pictures::getInstance()
{
	static Pictures instance;

	return instance;
}

