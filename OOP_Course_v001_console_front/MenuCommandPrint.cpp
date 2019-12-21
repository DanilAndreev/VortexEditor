#include "MenuCommandPrint.h"


MenuCommandPrint::MenuCommandPrint(TurboPipes::PipeDispatcherString* dispatcher) : 
	WMenu::MenuCommand(L"print", L"Prints a table of operations"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}

MenuCommandPrint::~MenuCommandPrint() {}

void MenuCommandPrint::handleCommnad(wstring inputData) {
	MagicJSON::JsonObject json;
	
	json.addString(L"command_type", L"get_data");
	json.addString(L"data_type", L"all");
	wstring message = json.toString();
	this->dispatcher->throwMessage(message);
}
