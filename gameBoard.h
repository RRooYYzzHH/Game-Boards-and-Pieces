/*
We can consider this file as the implementation of the main functions.

It has three funcitons:
1. parseDimension
    the purpose of this function is to parse the dimension (first line) of the game board
2. parseGamePieces
    the purpose of this function is to parse all the game pieces (second line to last line)
3. printBoard
    this function is to print out the whole game board
*/

#pragma once
#include "stdafx.h"
#include "header.h"
#include "gamePieces.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int parseDimensions(ifstream &ifs, unsigned int &h, unsigned int &v);
int parseGamePieces(ifstream &ifs, vector<game_piece> &gamePieces, unsigned int h, unsigned int v);
int printBoard(const vector<game_piece> &, unsigned int, unsigned int);