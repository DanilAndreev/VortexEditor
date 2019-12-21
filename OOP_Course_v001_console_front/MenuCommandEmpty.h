#pragma once
#include "MenuCommand.h"

class MenuCommandEmpty : public MenuCommand {
public:
	MenuCommandEmpty(wstring key) : MenuCommand(key, L""){}
	~MenuCommandEmpty() {}
public:
	void handleCommnad(wstring inputData) override {}
};
