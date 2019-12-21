#include <iostream>

#include "MagicJSON.h"
#include "ATable.h"
#include "Menu.h"
#include "MenuCommandPrint.h"

using namespace std;

int main() {
	//TestPipeable p;

	Menu menu;
	menu.addCommand(new MenuCommandPrint(L"print", L"Prints table"));
	menu.start();




	wcout << "Client connecting to server" << endl;
	//TurboPipes::PipeDispatcherString dispatcher(L"\\\\.\\pipe\\$MyPipe$", false, &p);
	wcout << "connected" << endl;

	while (true) {
		wstring message;
		getline(wcin, message);
		//dispatcher.throwMessage(message);
	}
}
