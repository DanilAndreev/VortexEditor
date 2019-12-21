#include "MenuCommandPrint.h"


MenuCommandPrint::MenuCommandPrint(TurboPipes::PipeDispatcherString* dispatcher) : 
	WMenu::MenuCommand(L"print", L"Prints a table of all operations"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}

MenuCommandPrint::~MenuCommandPrint() {}

void MenuCommandPrint::handleCommnad(wstring inputData) {
	MagicJSON::JsonObject json;
	
	json.addString(COMMAND_TYPE_KEY, COMMAND_GET_DATA);
	json.addString(DATA_TYPE_KEY, DATA_ALL);
	wstring message = json.toString();
	this->dispatcher->throwMessage(message);
}
