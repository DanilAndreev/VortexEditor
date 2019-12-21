#include "MenuCommandPrint.h"


MenuCommandPrint::MenuCommandPrint(wstring key, wstring description) : WonderMenu::MenuCommand(key, description) {
}

MenuCommandPrint::~MenuCommandPrint()
{
}

void MenuCommandPrint::handleCommnad(wstring inputData) {
	wcout << "command: " << inputData;
}
