#include "MenuCommandSave.h"
#include <iterator>
#include <sstream>
#include <vector>
#include <fstream>



MenuCommandSave::MenuCommandSave(TurboPipes::PipeDispatcherString* dispatcher) :
	WMenu::MenuCommand(L"save", L"Saves data to text or binary file"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandSave::~MenuCommandSave() {}


void MenuCommandSave::handleCommnad(wstring inputData) {
	MagicJSON::JsonObject json;
	json.addString(COMMAND_TYPE_KEY, COMMAND_SAVE);

	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());
	if (tokens.size() == 3) {
		if (tokens[1].compare(L"binary") == 0) {
			json.addString(SAVE_DATA_KEY, SAVE_BINARY);
		}
		if (tokens[1].compare(L"text") == 0) {
			json.addString(SAVE_DATA_KEY, SAVE_TEXT);
		}
		if (tokens[1].compare(L"binary") != 0 && tokens[1].compare(L"text") != 0) {
			wcout << "invalid arguments: invalid file type" << endl;
			wcout << "usage: save [text/binary] [filepath]" << endl;
			return;
		}
		json.addString(PATH_KEY, tokens[2]);
	}
	else {
		wcout << "invalid arguments" << endl;
		wcout << "usage: save [text/binary] [filepath]" << endl;
		return;
	}

	wstring message = json.toString();
	this->dispatcher->throwMessage(message);
}
