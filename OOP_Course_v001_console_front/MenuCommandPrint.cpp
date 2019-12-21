#include "MenuCommandPrint.h"


MenuCommandPrint::MenuCommandPrint(TurboPipes::PipeDispatcherString* dispatcher) : 
	WMenu::MenuCommand(L"print", L"Prints a table of operations"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}

MenuCommandPrint::~MenuCommandPrint() {}

void MenuCommandPrint::handleCommnad(wstring inputData) {
	this->dispatcher->throwMessage(inputData);
}
