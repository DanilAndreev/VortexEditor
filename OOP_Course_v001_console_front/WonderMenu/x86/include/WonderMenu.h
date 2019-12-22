#pragma once
/*
   MenuCommand.cpp, WonderMenu.cpp MenuCommand.h MenuCommandEmpty.h WonderMenu.h WonderMenuExceptions.h WMenu.h

   Copyright (C) 2019 Andrieiev Danil

   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this source code must not be misrepresented; you must not
	  claim that you wrote the original source code. If you use this source code
	  in a product, an acknowledgment in the product documentation would be
	  appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
	  misrepresented as being the original source code.

   3. This notice may not be removed or altered from any source distribution.

   Andrieiev Danil danssg08@gmail.com

   version 1.1.0
*/

#include <set>
#include <string>
#include <iostream>
#include "MenuCommand.h"
#include "WonderMenuExceptions.h"


namespace WMenu {
	using namespace std;

	typedef set<MenuCommand*, bool(*)(MenuCommand* less, MenuCommand* higher)> MSet;
	class WonderMenu : private MSet {
	protected:
		wstring exitCommand;
	public:
		WonderMenu(wstring exitCommand);
		WonderMenu();
		virtual ~WonderMenu();
		void addCommand(MenuCommand* command);
		void start();
	public:
		virtual void print() = 0;
	public:
		using MSet::size;
		using MSet::begin;
		using MSet::end;
		using MSet::iterator;
	private:
		MenuCommand* find(wstring key);
		static bool comparator(MenuCommand* less, MenuCommand* higher);
	};
}
