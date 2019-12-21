#include "MenuCommandFind.h"
#include <iterator>
#include <sstream>
#include <vector>



MenuCommandFind::MenuCommandFind(TurboPipes::PipeDispatcherString* dispatcher) : 
	WMenu::MenuCommand(L"find", L"Prints a table of finded operations"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandFind::~MenuCommandFind() {}

void MenuCommandFind::handleCommnad(wstring inputData) {
	MagicJSON::JsonObject json;
	json.addString(COMMAND_TYPE_KEY, COMMAND_GET_DATA);
	json.addString(DATA_TYPE_KEY, DATA_FILTERED);

	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());
	if(tokens.size() == 3){
		if (tokens[1].compare(L"integer") == 0) {
			json.addString(FILTER_TYPE_KEY, FILTER_TYPE_INTEGER);
			try {
				json.addInteger(FILTER_VALUE_KEY, stol(tokens[2]));
			}
			catch (invalid_argument e) {
				wcout << "invalid arguments: \"" << tokens[2] << "\" is not an integer" << endl;
			}
		}
		if (tokens[1].compare(L"string") == 0) {
			json.addString(FILTER_TYPE_KEY, FILTER_TYPE_STRING);
			json.addString(FILTER_VALUE_KEY, tokens[2]);
		}
	}
	else {
		wcout << "invalid arguments" << endl;
		wcout << "usage: find [type] [value]" << endl;
		return;
	}

	wstring message = json.toString();
	this->dispatcher->throwMessage(message);
}
