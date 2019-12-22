#include "InputChecker.h"
#include <stdexcept>

bool isDay(wstring& input) {
	try {
		int result = stoi(input);
		if (result > 0 && result <= 31) {
			return true;
		}
		return false;
	} 
	catch (invalid_argument e){
		return false;
	}
}

bool isMonth(wstring& input) {
	try {
		int result = stoi(input);
		if (result > 0 && result <= 12) {
			return true;
		}
		return false;
	}
	catch (invalid_argument e) {
		return false;
	}
}

bool isInteger(wstring& input) {
	try {
		stoi(input);
	}
	catch (invalid_argument e) {
		return false;
	}
	return true;
}

bool isName(wstring& input) {
	if (input.length() >= 1 && iswupper(input[0])) {
		return true;
	}
	return false;
}

wstring queryInput(bool(*checker)(wstring& str), wstring message) {
	wstring input;
	getline(wcin, input);
	while (!checker(input)) {
		wcout << message << endl;
		getline(wcin, input);
	}
	return input;
}


