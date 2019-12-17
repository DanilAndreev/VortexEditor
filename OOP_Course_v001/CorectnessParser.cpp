#include "CorectnessParser.h"



CorectnessParser::CorectnessParser() {
}


CorectnessParser::~CorectnessParser() {
}

bool CorectnessParser::checkName(string input) {
	if (input.length() > 0) {
		if (!(isalpha(input[0]) && isupper(input[0]))) {
			return false;
		}
	}
	for (int i = 0; i < input.length(); i++) {
		if (!(isalpha(input[i]) || input[i] == ' ' || input[i] == '-')) {
			return false;
		}
	}
	return true;
}

bool CorectnessParser::checkWord(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (!isalpha(input[i])) {
			return false;
		}
	}
	return true;
}

bool CorectnessParser::checkNumber(string input) {
	if (input.length() > 0) {
		if (!(isdigit(input[0]) || input[0] == '-')) {
			return false;
		}
	}
	for (int i = 1; i < input.length(); i++) {
		if (!(isdigit(input[i]) || input[i] == '.')) {
			return false;
		}
	}
	if (input.find_first_of('.') != input.find_last_of('.')) {
		return false;
	}
	return true;
}

bool CorectnessParser::checkIntegerNumber(string input) {
	if (input.length() > 0) {
		if (!(isdigit(input[0]) || input[0] == '-')) {
			return false;
		}
	}
	for (int i = 1; i < input.length(); i++) {
		if (!(isdigit(input[i]))) {
			return false;
		}
	}
	return true;
}

bool CorectnessParser::checkUnsignedIntegerNumber(string input) {
	if (!checkIntegerNumber(input)) {
		return false;
	}
	if (input.length() > 0) {
		if (!isdigit(input[0])) {
			return false;
		}
	}
	return true;
}

bool CorectnessParser::checkInfo(string input, bool(*corectnessChecker)(string), void(*wrongDataMessage)()) {
	bool temp = corectnessChecker(input);
	if (!temp) {
		wrongDataMessage();
	}
	return temp;
}
