#pragma once
#include "WonderMenu.h"
#include "ATable.h"
#include <iostream>
#include <string>

using namespace std;

class Menu : public WonderMenu::WonderMenu {
public:
	Menu();
	~Menu();
public:
	void print() override;
};

