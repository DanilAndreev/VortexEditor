#include "NetworkMessagesHandler.h"
#include "base_64.h"
#include "StatTools.h"
#include <locale>
#include <codecvt>
#include <string>
#include <chrono>
#include <ctime>


NetworkMessagesHandler::NetworkMessagesHandler(DailyReport* dailyReport) : dailyReport(dailyReport) {
	if (!this->dailyReport) {
		throw ZeroPointerException();
	}
}


NetworkMessagesHandler::~NetworkMessagesHandler() {}


void NetworkMessagesHandler::handleMessage(wstring& message) {
	try{
		std::time_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		char buff[30];
		ctime_s(buff, 30, &current_time);
		wcout << buff << "recieved: " << message << endl << endl;
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
				this->handleLoadBinaryFileMessage(json_message);
			}
			if (json_message.getString(LOAD_DATA_KEY).compare(LOAD_TEXT) == 0) {
				this->handleLoadTextFileMessage(json_message);
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_SAVE) == 0) {
			if (json_message.getString(SAVE_DATA_KEY).compare(SAVE_BINARY) == 0) {
				this->handleSaveBinaryFileMessage(json_message);
			}
			if (json_message.getString(SAVE_DATA_KEY).compare(SAVE_TEXT) == 0) {
				this->handleSaveTextFileMessage(json_message);
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_ADD_DATA) == 0) {
			if (json_message.getString(DATA_TYPE_KEY).compare(DATA_OPERATION) == 0) {
				this->handleAddOperationMessage(json_message);
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_GET_REPORT) == 0) {
			if (json_message.getString(REPORT_TYPE_KEY).compare(REPORT_STATISTIC) == 0) {
				this->handleReportStaticticMessage(json_message);
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_TERMINATE) == 0) {
			this->dispatcher->stopThread();
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


void NetworkMessagesHandler::handleSaveTextFileMessage(MagicJSON::JsonObject message) {
	MagicJSON::JsonObject answer_json;
	answer_json.addString(COMMAND_TYPE_KEY, COMMAND_SAVE);
	answer_json.addString(SAVE_DATA_KEY, SAVE_TEXT);
	answer_json.addString(PATH_KEY, message.getString(PATH_KEY));
	answer_json.addObject(VALUE_KEY, this->dailyReport->serialize());
	wstring answer_message = answer_json.toString();
	this->dispatcher->throwMessage(answer_message);
}


void NetworkMessagesHandler::handleLoadBinaryFileMessage(MagicJSON::JsonObject message) {
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	string sbuffer = converter.to_bytes(message.getString(VALUE_KEY));
	size_t size = message.getInteger(SIZE_KEY);
	byte* buffer = new byte[size];
	memcpy(buffer, base64_decode(sbuffer).c_str(), size*sizeof(byte));
	
	ofstream out("temp.binary", ios::binary);
	out.write((char*)buffer, size * sizeof(byte));
	out.close();

	delete[] buffer;
	try {
		ifstream in;
		in.exceptions(ifstream::failbit | ifstream::badbit);
		in.open("temp.binary", ios::binary);
		this->dailyReport->load(in);
		in.close();

		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_SUCCESS);
		answer_json.addString(SUCCESS_TYPE_KEY, SUCCESS_READING_FILE);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}
	catch (WrongInputDataException e) {
		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_ERROR);
		answer_json.addString(ERROR_TYPE_KEY, ERROR_INVALID_FILE);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}
	catch (wifstream::failure e) {
		wcout << "Error: error trying to access to temp.binary file" << endl;
	}
}

void NetworkMessagesHandler::handleSaveBinaryFileMessage(MagicJSON::JsonObject message) {
	try {
		ofstream out;
		out.exceptions(ifstream::failbit | ifstream::badbit);
		out.open("temp.binary", ios::binary);
		this->dailyReport->save(out);
		out.close();

		ifstream in;
		in.exceptions(ifstream::failbit | ifstream::badbit);
		in.open("temp.binary", ios::binary);

		in.seekg(0, in.end);
		size_t size = in.tellg();
		in.seekg(0, in.beg);
		byte* buffer = new byte[size];
		in.read((char*)buffer, size * sizeof(byte));
		in.close();
		string base_string = base64_encode(buffer, size * sizeof(byte));
		delete[] buffer;

		wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_SAVE);
		answer_json.addString(SAVE_DATA_KEY, SAVE_BINARY);
		answer_json.addInteger(SIZE_KEY, size);
		answer_json.addString(VALUE_KEY, converter.from_bytes(base_string));
		answer_json.addString(PATH_KEY, message.getString(PATH_KEY));
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}
	catch (wifstream::failure e) {
		wcout << "Error: error trying to access to temp.binary file" << endl;
	}
}


void NetworkMessagesHandler::handleAddOperationMessage(MagicJSON::JsonObject message) {
	MagicJSON::JsonObject json_operation = message.getObject(VALUE_KEY);
	bool isReturn = false;
	if (json_operation.getString(L"operation_type").compare(L"return") == 0) {
		isReturn = true;
	}

	long operation_day = json_operation.getInteger(L"operation_day");
	long operation_month = json_operation.getInteger(L"operation_month");
	long operation_year = json_operation.getInteger(L"operation_year");
	wstring abonent_name = json_operation.getString(L"abonent_name");
	wstring abonent_surename = json_operation.getString(L"abonent_surename");
	long abonent_month = json_operation.getInteger(L"abonent_month");
	long abonent_year = json_operation.getInteger(L"abonent_year");
	long disk_lenght = json_operation.getInteger(L"disk_length");
	wstring disk_name = json_operation.getString(L"disk_name");
	long disk_day = json_operation.getInteger(L"disk_day");
	long disk_month = json_operation.getInteger(L"disk_month");
	long disk_year = json_operation.getInteger(L"disk_year");
	wstring studio_name = json_operation.getString(L"studio_name");
	long studio_day = json_operation.getInteger(L"studio_day");
	long studio_month = json_operation.getInteger(L"studio_month");
	long studio_year = json_operation.getInteger(L"studio_year");



	try {
		Operation* operation = new Operation(
			Date2(operation_year, operation_month, operation_day), 
			Abonent(abonent_name, abonent_surename, abonent_year, abonent_month),
			Disk(Studio(studio_name, studio_year, studio_month, studio_day), 
			disk_lenght, disk_name, disk_year, disk_month, disk_day), isReturn);
		if (isReturn) {
			this->dailyReport->addReturn(operation);
		}
		else {
			this->dailyReport->addExtradition(operation);
		}
	}
	catch (WrongInputValuesException e) {
		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_ERROR);
		answer_json.addString(ERROR_TYPE_KEY, ERROR_INVALID_VALUES);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}

	MagicJSON::JsonObject answer_json;
	answer_json.addString(COMMAND_TYPE_KEY, COMMAND_SUCCESS);
	answer_json.addString(SUCCESS_TYPE_KEY, SUCCESS_ADDING_DATA);
	answer_json.addObject(VALUE_KEY, json_operation);
	answer_json.addString(DATA_TYPE_KEY, DATA_OPERATION);
	wstring answer_message = answer_json.toString();
	this->dispatcher->throwMessage(answer_message);
}

void NetworkMessagesHandler::handleReportStaticticMessage(MagicJSON::JsonObject message) {
	MagicJSON::JsonObject stat_json;
	stat_json.addFloat(L"average_length", StatTools::statistic<int>(this->dailyReport));
	stat_json.addFloat(L"average_symbols", StatTools::statistic<wstring>(this->dailyReport));

	MagicJSON::JsonObject answer_json;
	answer_json.addString(COMMAND_TYPE_KEY, COMMAND_GET_REPORT);
	answer_json.addString(REPORT_TYPE_KEY, REPORT_STATISTIC);
	answer_json.addObject(VALUE_KEY, stat_json);
	answer_json.addString(DATA_TYPE_KEY, DATA_OPERATION);
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
