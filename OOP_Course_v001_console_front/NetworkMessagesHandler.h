#pragma once
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include "ATable.h"
#include <string>
#include <iostream>

using namespace std;

class NetworkMessagesHandler : public TurboPipes::PipeableString {
public:
	NetworkMessagesHandler();
	~NetworkMessagesHandler();
public:
	void handleMessage(wstring& message) override;
protected:
	void handleSendAllDataMessage(MagicJSON::JsonObject message);
	void handleSaveTetMessage(MagicJSON::JsonObject message);
	void handleBinaryTetMessage(MagicJSON::JsonObject message);
	void handleAddDataSuccessMessage(MagicJSON::JsonObject message);
	static void addOperationToTable(MagicJSON::JsonObject operation, ATable::Table* table);
	static ATable::Table* constructTableForOperations(string name);
};

