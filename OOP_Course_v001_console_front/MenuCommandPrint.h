#pragma once
#include "MenuCommand.h"
#include <iostream>
#include <string>

using namespace std;

class MenuCommandPrint : public WonderMenu::MenuCommand {
public:
	MenuCommandPrint(wstring key, wstring description);
	~MenuCommandPrint();
public:
	void handleCommnad(wstring inputData) override;
};

