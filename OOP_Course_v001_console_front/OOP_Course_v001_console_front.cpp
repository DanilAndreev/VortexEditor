#include <iostream>
#include "MagicJSON.h"
#include "ATable.h"
#include "Menu.h"
#include "MenuCommandPrint.h"
#include "MenuCommandFind.h"
#include "MenuCommandLoad.h"
#include "MenuCommandSave.h"
#include "TurboPipes.h"
#include "NetworkMessagesHandler.h"

using namespace std;

int main() {
	

	Sleep(1000);
	NetworkMessagesHandler p;
	wcout << "Client connecting to server" << endl;
	TurboPipes::PipeDispatcherString dispatcher(L"\\\\.\\pipe\\$MyPipe$", false, &p);
	wcout << "connected" << endl;
	
	
	Menu menu;
	menu.addCommand(new MenuCommandPrint(&dispatcher));
	menu.addCommand(new MenuCommandFind(&dispatcher));
	menu.addCommand(new MenuCommandLoad(&dispatcher));
	menu.addCommand(new MenuCommandSave(&dispatcher));

	menu.start();

}
