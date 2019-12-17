#pragma once
#include "Object.h"
#include "Option.h"
#include "MenuExceptions.h"
#include "ATable.h"
#include "CorectnessParser.h"
#include <vector>

namespace Menu {
	class Menu : public Object {
	protected:
		vector <Option*>* options;
	public:
		Menu();
		~Menu();
		void start(); // starts input handling
		void addOption(Option* option); // adds option to menu
		Option* getOption(int index); // returns option on position index
	protected:
		Option* searchOptionByKey(string key); // returns option if found and nullptr if not
	};
}

