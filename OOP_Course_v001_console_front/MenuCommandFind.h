#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include <iostream>
#include <string>

using namespace std;

class MenuCommandFind : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandFind(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandFind();
public:
	void handleCommnad(wstring inputData) override;
};

