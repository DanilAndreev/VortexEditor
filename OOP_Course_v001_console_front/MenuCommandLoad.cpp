#include "MenuCommandLoad.h"
#include <iterator>
#include <sstream>
#include <vector>
#include <fstream>


MenuCommandLoad::MenuCommandLoad(TurboPipes::PipeDispatcherString* dispatcher) : 
	WMenu::MenuCommand(L"load", L"Loads data from text or binary file"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandLoad::~MenuCommandLoad() {}


void MenuCommandLoad::handleCommnad(wstring inputData) {
	MagicJSON::JsonObject json;
	json.addString(COMMAND_TYPE_KEY, COMMAND_LOAD);

	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());
	if (tokens.size() == 3) {
		if (tokens[1].compare(L"binary") == 0) {
			json.addString(LOAD_DATA_KEY, LOAD_BINARY);
		}
		if (tokens[1].compare(L"text") == 0) {
			json.addString(LOAD_DATA_KEY, LOAD_TEXT);
		}
		if (tokens[1].compare(L"binary") != 0 && tokens[1].compare(L"text") != 0) {
			wcout << "invalid arguments: invalid file type" << endl;
			wcout << "usage: load [text/binary] [filepath]" << endl;
			return;
		}
		try {
			wifstream file;
			file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			file.open(tokens[2]);
			wstring buffer;
			wstring token;
			while (!file.eof()) {
				file >> token;
				buffer.append(token);
			}
			json.addObject(VALUE_KEY, MagicJSON::JsonObject(buffer));
		}
		catch (wifstream::failure e) {
			wcout << "Error: error reading file" << endl;
			return;
		}	
		catch (MagicJSON::ErrorReadingTextException e) {
			wcout << "Error: invalid file data" << endl;
			return;
		}
	}
	else {
		wcout << "invalid arguments" << endl;
		wcout << "usage: load [text/binary] [filepath]" << endl;
		return;
	}

	wstring message = json.toString();
	this->dispatcher->throwMessage(message);
}
