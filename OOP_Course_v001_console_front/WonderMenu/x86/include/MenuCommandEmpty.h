#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "MenuCommand.h"


namespace WonderMenu {
	class MenuCommandEmpty : public MenuCommand {
	public:
		MenuCommandEmpty(wstring key) : MenuCommand(key, L"") {}
		~MenuCommandEmpty() {}
	public:
		void handleCommnad(wstring inputData) override {}
	};
}
