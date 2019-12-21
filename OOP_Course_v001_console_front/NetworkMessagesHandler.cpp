#include "NetworkMessagesHandler.h"



NetworkMessagesHandler::NetworkMessagesHandler()
{
}


NetworkMessagesHandler::~NetworkMessagesHandler()
{
}

void NetworkMessagesHandler::handleMessage(wstring& message) {
	wcout << "recieved: " << message << endl;
}
