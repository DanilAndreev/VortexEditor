#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include <iostream>
#include <string>

using namespace std;

class MenuCommandPrint : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandPrint(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandPrint();
public:
	void handleCommnad(wstring inputData) override;
};

