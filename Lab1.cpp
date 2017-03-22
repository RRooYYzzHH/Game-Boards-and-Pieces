// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "gamePieces.h"
#include "gameBoard.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	// Check the arguments numbers
	const char *programName = argv[command_line_argument::programName];
	string message = "Command line argument needs to be given!";
	if (argc != command_line_argument::expectedArguments) {
		int error = usageMessage(programName, message);
		if (error == message::fail_print_usageMessage) {
			cout << "Error: Failed to print usage message!" << endl;
		}
		else {
			cout << "Printed usage message!" << endl;
		}
		return error;
	}

	// Parse the input file
	const char *filename = argv[command_line_argument::fileName];
	ifstream op = ifstream(filename);
	if (!op.is_open())
	{
		cout << "Error: the file given does not exist!" << endl;
		return message::can_not_open_file;
	}

	// Extract dimensions
	ifstream & ifs = op;
	unsigned int hori = 0;
	unsigned int vert = 0;
	unsigned int &h = hori;
	unsigned int &v = vert;

	int parseDimension;
	do
	{
		parseDimension = parseDimensions(ifs, h, v);
	} while (parseDimension == message::cannot_extract_dimensions);

	if (parseDimension == message::cannot_read_line)
	{
		cout << "Error: cannot extract dimensions from the given file!" << endl;
		return message::cannot_read_line;
	}

	// Create the vector
	int size = hori * vert;
	vector<game_piece> gamePieces;
	for (int i = 0; i < size; i++) 
	{
		game_piece tmp;
		tmp.color = piece_color::no_color;
		tmp.displayed = " ";
		tmp.name = "";
		gamePieces.push_back(tmp);
	}
	vector<game_piece> &gp = gamePieces;

	// Parse the Game Board
	int parseGP = parseGamePieces(ifs, gp, hori, vert);
	if (parseGP == message::fail_to_find_def)
	{
		cout << "Error: cannot find any well formed piece definitions!" << endl;
		return message::fail_to_find_def;
	}
	else if (parseGP == message::fail_after_opening)
	{
		cout << "Error: failed after opening the fail; the fail may be broken!" << endl;
		return message::fail_after_opening;
	}

	// Print the game board
	int printGB = printBoard(gp, hori, vert);
	if (printGB == message::size_not_match)
	{
		cout << "Error: the size of the vector might not match the dimensions of the game board that were passed in!" << endl;
		return message::size_not_match;
	}
	return message::success;
}

