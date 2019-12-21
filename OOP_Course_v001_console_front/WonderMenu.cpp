#include "WonderMenu.h"
#include "MenuCommandEmpty.h"


WonderMenu::WonderMenu() : MSet(&comparator){
}


WonderMenu::~WonderMenu()
{
}

void WonderMenu::addCommand(MenuCommand* command) {
	this->insert(command);
}

void WonderMenu::start() {
	while (true) {
		wstring buffer;
		wstring command;
		wcin >> command;
		for (size_t i = 0; i < command.length() + 1; i++) {
			wcin.unget();
		}
		getline(wcin, buffer);


		wcout << "command: " << command << endl;
		wcout << "line: " << buffer << endl;

		try {
			MenuCommand* item = this->find(command);
		}
		catch (NoObjectFoundException e) {
			wcout << L"Error: Unknown command" << endl;
		}
	}
}

MenuCommand* WonderMenu::find(wstring key) {
	MenuCommandEmpty finder(key);
	iterator item =  MSet::find(&finder);
	if (item == this->cend()) {
		throw NoObjectFoundException();
	}
	return *item;
}

bool WonderMenu::comparator(MenuCommand* less, MenuCommand* higher) {
	int comparingResult = less->getKey().compare(higher->getKey());
	if (comparingResult == -1) {
		return true;
	} 
	return false;
}
