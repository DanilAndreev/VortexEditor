#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include <iostream>
#include <string>


class MenuCommandStat : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandStat(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandStat();
public:
	void handleCommnad(wstring inputData) override;
};

