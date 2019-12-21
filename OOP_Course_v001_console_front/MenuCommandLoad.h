#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include <iostream>
#include <string>


class MenuCommandLoad : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandLoad(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandLoad();
public:
	void handleCommnad(wstring inputData) override;
};

