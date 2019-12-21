#include <iostream>

#include "MagicJSON.h"
#include "ATable.h"
#include "Menu.h"
#include "MenuCommandPrint.h"
#include "TurboPipes.h"
#include "NetworkMessagesHandler.h"

using namespace std;

int main() {
	Sleep(100);
	NetworkMessagesHandler p;
	wcout << "Client connecting to server" << endl;
	TurboPipes::PipeDispatcherString dispatcher(L"\\\\.\\pipe\\$MyPipe$", false, &p);
	wcout << "connected" << endl;
	
	
	Menu menu;
	menu.addCommand(new MenuCommandPrint(&dispatcher));

	menu.start();

}
