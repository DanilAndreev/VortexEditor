#include "MenuCommandExit.h"
#include <iterator>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdexcept>

MenuCommandExit::MenuCommandExit(TurboPipes::PipeDispatcherString* dispatcher) :
	WMenu::MenuCommand(L"exit", L"Stops the session"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandExit::~MenuCommandExit()
{
}

void MenuCommandExit::handleCommnad(wstring inputData) {
	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());

	if (tokens.size() > 2) {
		wcout << "invalid arguments" << endl;
		wcout << "usage: exit" << endl;
		wcout << "usage: exit -stop_server" << endl;
		return;
	}
	try {
		
		if (tokens.at(1).compare(L"-stop_server") == 0) {
			MagicJSON::JsonObject message_json;
			message_json.addString(COMMAND_TYPE_KEY, COMMAND_TERMINATE);
			wstring string_message = message_json.toString();
			this->dispatcher->throwMessage(string_message);
			Sleep(100);
		}
		else {
			wcout << "invalid arguments" << endl;
			wcout << "usage: exit" << endl;
			wcout << "usage: exit -stop_server" << endl;
			return;
		}
	}
	catch (std::out_of_range e) {}
	this->dispatcher->stopThread();
}
