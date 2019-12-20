#include <iostream>

#include "TestPipeable.h"
#include "MagicJSON.h"

using namespace std;

int main() {
	TestPipeable p;
	wcout << "Client connecting to server" << endl;
	PipeDispatcher dispatcher(L"\\\\.\\pipe\\$MyPipe$", false, &p);
	wcout << "connected" << endl;

	while (true) {
		wstring message;
		getline(wcin, message);
		dispatcher.throwMessage(message);
	}
}
