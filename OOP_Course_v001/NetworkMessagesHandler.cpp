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
			if (json_message.getString(DATA_TYPE_KEY).compare(DATA_ALL) == 0) {
				this->handleGetAllMessage();
			}
			if (json_message.getString(DATA_TYPE_KEY).compare(DATA_FILTERED) == 0) {
				this->handleGetFilteredMessage(json_message);
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_LOAD) == 0) {
			if (json_message.getString(LOAD_DATA_KEY).compare(LOAD_BINARY) == 0) {
				//------------------ TODO
			}
			if (json_message.getString(LOAD_DATA_KEY).compare(LOAD_TEXT) == 0) {
				this->handleLoadTextFileMessage(json_message);
			}
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

void NetworkMessagesHandler::handleGetFilteredMessage(MagicJSON::JsonObject message) {
	MagicJSON::JsonObject dailyReport_json;

	MagicJSON::JsonArray returns;
	MagicJSON::JsonArray extraditions;
	for (size_t i = 0; i < this->dailyReport->getReturnsSize(); i++) {
		Operation* operation = this->dailyReport->getReturn(i);
		if (message.getString(FILTER_TYPE_KEY).compare(FILTER_TYPE_STRING) == 0) {
			if (operation->getAbonent().getName().compare(message.getString(FILTER_VALUE_KEY)) == 0) {
				returns.addObject(buildOperationJson(operation));
			}
		}
		if (message.getString(FILTER_TYPE_KEY).compare(FILTER_TYPE_INTEGER) == 0) {
			if (operation->getAbonent().getYear() == message.getInteger(FILTER_VALUE_KEY)) {
				returns.addObject(buildOperationJson(operation));
			}
		}
	}
	for (size_t i = 0; i < this->dailyReport->getExtraditionsSize(); i++) {
		Operation* operation = this->dailyReport->getExtradition(i);
		if (message.getString(FILTER_TYPE_KEY).compare(FILTER_TYPE_STRING)) {
			if (operation->getAbonent().getName().compare(message.getString(FILTER_VALUE_KEY)) == 0) {
				extraditions.addObject(buildOperationJson(operation));
			}
		}
		if (message.getString(FILTER_TYPE_KEY).compare(FILTER_TYPE_INTEGER) == 0) {
			if (operation->getAbonent().getYear() == message.getInteger(FILTER_VALUE_KEY)) {
				extraditions.addObject(buildOperationJson(operation));
			}
		}
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

void NetworkMessagesHandler::handleLoadTextFileMessage(MagicJSON::JsonObject message) {
	try {
		MagicJSON::JsonObject data = message.getObject(VALUE_KEY);
		this->dailyReport->deserialize(data);

		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_SUCCESS);
		answer_json.addString(SUCCESS_TYPE_KEY, SUCCESS_READING_FILE);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}
	catch (IncorrectObjectDataException){
		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_ERROR);
		answer_json.addString(ERROR_TYPE_KEY, ERROR_INVALID_FILE);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}
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
