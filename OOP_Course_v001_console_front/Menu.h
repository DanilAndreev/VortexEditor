#pragma once
#include "WMenu.h"
#include "ATable.h"
#include <iostream>
#include <string>
#include <mutex>

using namespace std;

class Menu : public WMenu::WonderMenu {
public:
	Menu();
	~Menu();
public:
	void print() override;
};

