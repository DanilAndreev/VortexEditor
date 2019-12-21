#include "NetworkMessagesHandler.h"



NetworkMessagesHandler::NetworkMessagesHandler(DailyReport* dailyReport) : dailyReport(dailyReport) {
	if (!this->dailyReport) {
		throw ZeroPointerException();
	}
}


NetworkMessagesHandler::~NetworkMessagesHandler() {}

void NetworkMessagesHandler::handleMessage(wstring& message) {
	try{
		wcout << "recieved: " << message << endl;
		MagicJSON::JsonObject json_message(message);
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_GET_DATA) == 0) {
			this->handleGetAllMessage();
		}
	}
	catch (MagicJSON::JsonException e) {
		wcout << "Error: recieved error type message" << endl;
		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_ERROR);
		answer_json.addString(ERROR_TYPE_KEY, ERROR_INVALID_COMMAND);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}

}

void NetworkMessagesHandler::handleGetAllMessage() {
	MagicJSON::JsonObject dailyReport_json;

	MagicJSON::JsonArray returns;
	MagicJSON::JsonArray extraditions;
	for (size_t i = 0; i < this->dailyReport->getReturnsSize(); i++) {
		Operation* operation = this->dailyReport->getReturn(i);
		returns.addObject(buildOperationJson(operation));
	}
	for (size_t i = 0; i < this->dailyReport->getExtraditionsSize(); i++) {
		Operation* operation = this->dailyReport->getExtradition(i);
		extraditions.addObject(buildOperationJson(operation));
	}
	dailyReport_json.addArray(L"returns", returns);
	dailyReport_json.addArray(L"extraditions", extraditions);

	MagicJSON::JsonObject answer_json;
	answer_json.addString(COMMAND_TYPE_KEY, COMMAND_SEND_DATA);
	answer_json.addString(DATA_TYPE_KEY, DATA_ALL);
	answer_json.addObject(VALUE_KEY, dailyReport_json);
	wstring answer_message = answer_json.toString();
	this->dispatcher->throwMessage(answer_message);
}

MagicJSON::JsonObject NetworkMessagesHandler::buildOperationJson(Operation* operation) {
	MagicJSON::JsonObject operation_json;
	operation_json.addInteger(L"operation_day", operation->getDate().getDay());
	operation_json.addInteger(L"operation_month", operation->getDate().getMonth());
	operation_json.addInteger(L"operation_year", operation->getDate().getYear());
	operation_json.addInteger(L"operation_is_return", operation->isReturn());

	operation_json.addString(L"abonent_name", operation->getAbonent().getName());
	operation_json.addString(L"abonent_surename", operation->getAbonent().getSurename());
	operation_json.addInteger(L"abonent_year", operation->getAbonent().getYear());
	operation_json.addInteger(L"abonent_month", operation->getAbonent().getMonth());

	operation_json.addInteger(L"disk_length", operation->getDisk().getLength());
	operation_json.addString(L"disk_name", operation->getDisk().getName());
	operation_json.addInteger(L"disk_day", operation->getDisk().getDay());
	operation_json.addInteger(L"disk_month", operation->getDisk().getMonth());
	operation_json.addInteger(L"disk_year", operation->getDisk().getYear());

	operation_json.addInteger(L"studio_day", operation->getDisk().getStudio().getDay());
	operation_json.addInteger(L"studio_month", operation->getDisk().getStudio().getMonth());
	operation_json.addInteger(L"studio_year", operation->getDisk().getStudio().getYear());
	operation_json.addString(L"studio_name", operation->getDisk().getStudio().getName());
	return operation_json;
}
