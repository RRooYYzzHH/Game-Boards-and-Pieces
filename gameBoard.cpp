

#include "stdafx.h"
#include "header.h"
#include "gamePieces.h"
#include "gameBoard.h"

using namespace std;

int parseDimensions(ifstream &ifs, unsigned int &h, unsigned int &v) {
	string line;
	if (!getline(ifs, line)) 
	{
		return message::cannot_read_line;
	}
	else 
	{
		istringstream iss(line);
		int first;
		iss >> first;
		if (first < 0) 
		{
			return message::cannot_extract_dimensions;
		}
		int second;
		iss >> second;
		if (second < 0)
		{
			return message::cannot_extract_dimensions;
		}
		else
		{
			h = first;
			v = second;
		}
		return message::success;
	}
}

int parseGamePieces(ifstream &ifs, vector<game_piece> &gamePieces, unsigned int h, unsigned int v) {
	int number = 0;
	string line;
	while (getline(ifs, line)) {
		if (ifs.fail()) 
		{
			return message::fail_after_opening;
		}
		int judge = 1;
		string color;
		string name;
		string display;
		unsigned int hor;
		unsigned int ver;

		istringstream iss(line);
		string ss;
		for (int i = 1; i <= 5; i++)
		{
			if (!(iss >> ss))
			{
				judge = 0;
				break;
			}
			if (i == 1) 
			{
				color = ss;
			}
			else if (i == 2)
			{
				name = ss;
			}
			else if (i == 3)
			{
				display = ss;
			}
			else if (i == 4)
			{
				hor = stoi(ss);
			}
			else
			{
				ver = stoi(ss);
			}
		}

		int colorValue = changeColorToValue(color);
		if (judge == 0 || colorValue == 4 || colorValue == 5 || hor >= h || ver >= v) 
		{
			continue;
		}
		else 
		{
			int index = h * ver + hor;
			gamePieces[index].name = name;
			gamePieces[index].displayed = display;
			if (colorValue == 1) 
			{
				gamePieces[index].color = piece_color::red;
			}
			else if (colorValue == 2)
			{
				gamePieces[index].color = piece_color::black;
			}
			else
			{
				gamePieces[index].color = piece_color::white;
			}
			number++;
		}
	}
	if (number == 0) 
	{
		return message::fail_to_find_def;
	}
	else
	{
		return message::success;
	}
}

int printBoard(const vector<game_piece> &gamePieces, unsigned int hori, unsigned int vert) {
	if (gamePieces.size() != hori * vert) 
	{
		return message::size_not_match;
	}
	for (int i = vert - 1; i >= 0; i--) {
		for (int j = 0; j < hori; j++) {
			int index = hori * i + j;
			string display = gamePieces[index].displayed;
			cout << display << " ";
		}
		if (i != 0)
		{
			cout << endl;
		}
	}
	return message::success;
}