#include <iostream>

#include "MagicJSON.h"
#include "ATable.h"
#include "WonderMenu.h"

using namespace std;

int main() {
	//TestPipeable p;

	WonderMenu menu;
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
