#pragma once
#include "Object.h"
#include <string>

class CorectnessParser : public Object {
public:
	CorectnessParser();
	~CorectnessParser();
	static bool checkName(string input); // returns true if input string is a name and false if not
	static bool checkWord(string input); // returns true if input string is a one word and false if not
	static bool checkNumber(string input); // returns true if input string is a number and false if not
	static bool checkIntegerNumber(string input); // returns true if input string is an integer number and false if not
	static bool checkUnsignedIntegerNumber(string input); // returns true if input string is a positive integer number and false if not
	bool checkInfo(string input, bool (*corectnessChecker)(string), void (*wrongDataMessage)()); // returns value, returned by function corectnessChecker, if false -> calls wrongDataMessage function
};
