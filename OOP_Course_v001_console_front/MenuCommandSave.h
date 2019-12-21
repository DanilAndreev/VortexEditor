#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include <iostream>
#include <string>

class MenuCommandSave : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandSave(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandSave();
public:
	void handleCommnad(wstring inputData) override;
};

