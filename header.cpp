#include "stdafx.h"
#include "header.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int usageMessage(const char *programName, string message) {
	try {
		cout << "Usage: " << message << endl;
		cout << message << endl;
		return message::success_print_usageMessage;
	}
	catch (int error) {
		cout << "Error: " << error << endl;
		return message::fail_print_usageMessage;
	}
}

void changeToLowercase(string &s) {
	int length = s.length();
	char tmp[1024];
	strcpy_s(tmp, s.c_str());
	for (int i = 0; i < length; i++) {
		int judge = int(tmp[i]);
		if (judge >= 65 && judge <= 90) {
			tmp[i] = int(tmp[i]) + 32;
		}
	}
	s = string(tmp);
}