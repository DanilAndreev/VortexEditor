#pragma once
/* Copyright 2019 Andrieiev Danil */
#include <set>
#include <string>
#include <iostream>
#include "MenuCommand.h"
#include "WonderMenuExceptions.h"


namespace WonderMenu {
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
