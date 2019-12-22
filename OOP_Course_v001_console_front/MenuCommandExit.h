#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include <iostream>
#include <string>

using namespace std;


class MenuCommandExit : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandExit(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandExit();
public:
	void handleCommnad(wstring inputData) override;
};

