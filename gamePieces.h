/*
We can consider this file as the construction of the game pieces.

First, it defines a enumeration for different colors, and then defines the struct for the game pieces.

Second, this header file contains two functions:
1. changeValueToColor (change int type color to string type color)
2. changeColorToValue (change string type color to int type color)
*/


#pragma once
#include "stdafx.h"
#include "header.h"

using namespace std;

enum piece_color
{
	red = 1,
	black = 2,
	white = 3,
	invalid_color = 4,
	no_color = 5
};

struct game_piece
{
	piece_color color;
	string name;
	string displayed;
};

//function
string changeValueToColor(int colorValue);
int changeColorToValue(string color);