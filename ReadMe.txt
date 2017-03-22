========================================================================
    CSE 332 Lab1 : Game Boards and Pieces
		By Zihao Yang (445432) zihao.yang@wustl.edu
========================================================================
1. Brief summary of my program:
     the purpose of this program is to open the txt file, which contains the information of some game pieces. 
And then parse the file, read the content and print out the whole game board. Also, my program can deal will
differents kinds of errors during the whole process.

2. Brief summary of all the files of my program:
(1) header.h and header.cpp:

This file is actually a support file.

First, this header file contains two enumrations, including command_line_argument and message. And there are 
totally 9 different messages for our program.

Second, this header file also contains two functions:
	1. usageMessage (handle the usage message)
	2. changeToLowercase (change a string to lower case)

(2) gamePieces.h and gamePieces.cpp:

We can consider this file as the construction of the game pieces.

First, it defines a enumeration for different colors, and then defines the struct for the game pieces. For a 
game piece, it needs to contain name, color, and displayed name.

Second, this header file contains two functions:
	1. changeValueToColor (change int type color to string type color)
	2. changeColorToValue (change string type color to int type color)


(3) gameBoard.h and gameBoard.cpp:

We can consider this file as the implementation of the main functions.

It has three funcitons:
	1. parseDimension
    		the purpose of this function is to parse the dimension (first line) of the game board
	2. parseGamePieces
    		the purpose of this function is to parse all the game pieces (second line to last line)
	3. printBoard
    		this function is to print out the whole game board

3. The way to run my program is:
      first create a txt file and put this file into project debug folder. And then use the command
line "Lab1.exe fileName" to run my program   

4. Results of using "chess.txt" and "checkers.txt":
(1) Lab1.exe checkers.txt:
  O   O   O   O
O   O   O   O
  O   O   O   O


X   X   X   X
  X   X   X   X
X   X   X   X

(2) Lab1.exe chess.txt:
r s b q k b s r
p p p p p p p p




P P P P P P P P
P S B Q K B S R

5. There are totally 9 differents kinds of message:
   (1) success = 0: the main function will return 0 if there is no error
   (2) can_not_open_file = 1: the main function will return 1 if it can't open the file.
   (3) fail_print_usageMessage = 2: the main function will return 2 if it calls the usage function
              and fail to print the usage message
   (4) success_print_usageMessage = 3: the main function will return 3 if it calls the usage function
              and success to print the usage message
   (5) fail_after_opening = 4: the main function will return 4 if it fails after opening the file
   (6) cannot_read_line = 5: cannot read any line from the given file
   (7) cannot_extract_dimensions = 6: can not extract any dimension from the given file
   (8) fail_to_find_def = 7: cannot find any well formed piece definitions
   (9) size_not_match = 8: the size of the vector doesn't match the dimensions of the game board that 
                           were passed in	

6. I ran 4 differents cases: (the file name is "input_file.txt")

   Case one:  the command line were: "Lab1.exe" 
        My program will call the usage message function and my program will return 2 or 3. The reason
        is that there is no input argument, so my program will call the usage message function.
   Case two:  the command line were: "Lab1.exe file.txt"
        My program will return the value 1. The reason is that there is no file called "file.txt".
        My program cannot open the file, so it will give us the value 1
   Case three:  the command line were: "Lab1.exe checkers.txt" or "Lab1.exe chess.txt"
        My program will return 0. This means that there is no error during the execution.
   Case four: the given file contains no dimension (empty)
        My program will return 6 (cannot extract dimension)
   Case five: the given file contains only dimension (one line)
        My program will return 7 (cannot find any well formed definition)

