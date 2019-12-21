#pragma once
#include "TurboPipes.h"
#include "DailyReport.h"
#include "NetworkMessageKeys.h"
#include <string>
#include <iostream>

using namespace std;

class NetworkMessagesHandler : public TurboPipes::PipeableString {
protected:
	DailyReport* dailyReport;
public:
	NetworkMessagesHandler(DailyReport* dailyReport);
	~NetworkMessagesHandler();
public:
	void handleMessage(wstring& message) override;
protected:
	void handleGetAllMessage();
	void handleGetFilteredMessage(MagicJSON::JsonObject message);
	void handleLoadTextFileMessage(MagicJSON::JsonObject message);
	void handleSaveTextFileMessage(MagicJSON::JsonObject message);
	static MagicJSON::JsonObject buildOperationJson(Operation* operation);
};

