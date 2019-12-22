#include <iostream>
#include "Date2.h"
#include "DailyReport.h"
#include "MagicJSON.h"

#include "NetworkMessagesHandler.h"


int main() {
	wcout << "Copyright (C) Andrieiev Danil 2019" << endl;
	wcout << "Vortex Server startup" << endl;
	//creating new daily report
	DailyReport* report = new DailyReport();

	//creating network message handler
	NetworkMessagesHandler* p = new NetworkMessagesHandler(report);
	wcout << "Server is waiting for client connection" << endl;
	//creating network dispatcher
	TurboPipes::PipeDispatcherString dsp(L"\\\\.\\pipe\\$MyPipe$", true, p);
	wcout << "Client has been connected to server" << endl;

	//waiting for network dispatcher therad
	WaitForSingleObject(dsp.getThreadHandle(), INFINITE);
	delete p;
}
