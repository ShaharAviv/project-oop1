#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "StartingMenu.h"
#include <iostream>

//------SHAHAR----

int main()
{
	srand((unsigned)time(NULL));
	StartingMenu menu1;
	menu1.Play();
	return EXIT_SUCCESS;
}
