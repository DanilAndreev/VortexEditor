#include <iostream>
#include "MagicJSON.h"
#include "ATable.h"
#include "Menu.h"
#include "MenuCommandPrint.h"
#include "MenuCommandFind.h"
#include "MenuCommandLoad.h"
#include "MenuCommandSave.h"
#include "MenuCommandAdd.h"
#include "MenuCommandStat.h"
#include "MenuCommandExit.h"
#include "TurboPipes.h"
#include "NetworkMessagesHandler.h"
#include <vector>
#include <locale>
#include <codecvt>
#include <string>

using namespace std;

const LPCWSTR PIPE_NAME = L"\\pipe\\$MyPipe$";
wstring PIPE_ADRESS;

int main(int argc, char* argv[]) {
	wcout << "Copyright (C) Andrieiev Danil 2019" << endl;
	wcout << "Vortex Client startup" << endl;
	// checking arguments
	vector<string> args;
	for (int i = argc - 1; i > 0; i--) {
		args.push_back(string(argv[i]));
	}

	if (args.size() > 1) {
		wcout << "Invalid arguments: " << endl << "usage: program.exe [server ip or localhost]" << endl;
		return -1;
	}
	if (args.size() == 1) {
		if (args[0].compare("localhost")) {
			PIPE_ADRESS = L"\\\\.";
			PIPE_ADRESS.append(PIPE_NAME);
		}
		else {
			wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
			PIPE_ADRESS.append(L"\\\\");
			PIPE_ADRESS = converter.from_bytes(args[0]);
			PIPE_ADRESS.append(PIPE_NAME);
		}
	}
	else {
		PIPE_ADRESS = L"\\\\.";
		PIPE_ADRESS.append(PIPE_NAME);
	}


	// creating network messages handler
	NetworkMessagesHandler p;
	wcout << "Client attempting to connect to server" << endl;
	// creating network dispatcher
	TurboPipes::PipeDispatcherString dispatcher(PIPE_ADRESS, false, &p);
	wcout << "Client has been connected" << endl;
	
	// creating menu
	Menu menu;
	// adding commands menu
	menu.addCommand(new MenuCommandPrint(&dispatcher));
	menu.addCommand(new MenuCommandFind(&dispatcher));
	menu.addCommand(new MenuCommandLoad(&dispatcher));
	menu.addCommand(new MenuCommandSave(&dispatcher));
	menu.addCommand(new MenuCommandAdd(&dispatcher));
	menu.addCommand(new MenuCommandStat(&dispatcher));
	menu.addCommand(new MenuCommandExit(&dispatcher));

	// starting menu loop
	menu.start();
}
