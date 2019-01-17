#pragma once


enum Object_t
{
	Robot_type,//0
	SmartGuard_type, //1
	StupidGuard_type, //2
	Rock_type, //3
	Wall_type, //4
	Door_type, //5
	Bomb_type, //6
	Boom_type, //7
	Max
};

enum Direction_t
{
	Right,//0
	Down,//1
	Up,//2
	Left,//3,
	Wait,//4
	Max_d
};

enum Chars_t
{
	Robot_c = '/' ,//0
	Guard_c = '!', //1
	Smart_Guard_c = '%', //1
	Stupid_Guard_c = '^', //1
	Rock_c = '@', //2
	Wall_c = '#', //3
	Door_c = 'D', //4
	Bomb_c = '*', //5
	Max_c
};

enum Photo_t
{
	StartingMenu_b,
	StartButton_b,
	ExitButton_b,
	ResumeButton_b,
	HelpButton_b,
	Max_b
};