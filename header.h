/*
We can consider this header file as support file.

First, this header file contains two enumrations, including command_line_argument and message. And there are totally 9 different messages for our program.

Second, this header file also contains two functions:
1. usageMessage (handle the usage message)
2. changeToLowercase (change a string to lower case)
*/


#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <string>

using namespace std;

//create enumeration (pro.6)
enum command_line_argument { programName, fileName, expectedArguments = 2 };
enum message { success = 0, can_not_open_file = 1, fail_print_usageMessage = 2, success_print_usageMessage = 3, fail_after_opening = 4, cannot_read_line = 5, cannot_extract_dimensions = 6, 
	fail_to_find_def = 7, size_not_match = 8};

// Function prototypes
int usageMessage(const char *programName, string message);
void changeToLowercase(string &s);

#endif#pragma once
