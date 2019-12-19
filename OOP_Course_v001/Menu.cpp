#include "Menu.h"


namespace Menu {
	Menu::Menu() {
		this->options = new vector<Option*>();
	}

	Menu::~Menu(){}

	void Menu::start() {
		//creating new parser
		CorectnessParser* parser = new CorectnessParser();

		// creating new table
		ATable::Table* table = new ATable::Table(ATable::DefaultAppearance(), "Menu");
		//adding columns to table
		table->addColumn(new ATable::SimpleColumn("Command", 20));
		table->addColumn(new ATable::ConstColumn("-->"));
		table->addColumn(new ATable::SimpleColumn("Command id", 10));
		// adding cells to table;
		for (int i = 0; i < this->options->size(); i++) {
			table->addCell(0, new ATable::StringCell(this->getOption(i)->getText()));
			table->addCell(2, new ATable::StringCell(this->getOption(i)->getKey()));
		}
		table->addCell(0, new ATable::StringCell("Exit"));
		table->addCell(2, new ATable::StringCell("exit"));

		// start of command handler loop
		string key;
		do {
			do {
				//printing table with commands to stream cout
				table->print(cout);
				cout << "Enter a key: ";
				// getting input from cin to key
				getline(cin, key);
			} while (key != "exit" && !parser->checkInfo(key, parser->checkWord, []() {cout << "Invalid input data, enter one word" << endl; }));
			// searching option in commands array with inputed key
			Option* option = this->searchOptionByKey(key);
			if (!option && key != "exit") {
				cout << "This is no command with key: " << key << endl;
			}
			else if (key != "exit"){
				option->selected(); // calling callback function in selected command
			}
		} while (key != "exit");


		delete parser;
	}

	void Menu::addOption(Option* option) {
		if (searchOptionByKey(option->getKey()) || option->getKey() == "exit") {
			throw new KeyAlreadyExistException();
		}
		this->options->push_back(option);
	}

	Option* Menu::getOption(int index) {
		try {
			return (*(this->options))[index];
		}
		catch (...) {
			throw new IDOutOfRangeException();
		}
	}

	Option* Menu::searchOptionByKey(string key) {
		for (int i = 0; i < this->options->size(); i++) {
			try {
				if (this->getOption(i)->getKey() == key) {
					return this->getOption(i);
				}
			}
			catch (IDOutOfRangeException* e) {
				break;
			}
		}
		return nullptr;
	}

}

