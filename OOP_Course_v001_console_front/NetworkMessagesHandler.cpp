#include "NetworkMessagesHandler.h"
#include "Directories.h"
#include "base_64.h"
#include <locale>
#include <codecvt>
#include <fstream>

mutex console_writing_mutex;

NetworkMessagesHandler::NetworkMessagesHandler() {}


NetworkMessagesHandler::~NetworkMessagesHandler() {}


void NetworkMessagesHandler::handleMessage(wstring& message) {
	try {
		MagicJSON::JsonObject json_message(message);
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_SEND_DATA) == 0) {
			this->handleSendAllDataMessage(json_message);
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_SUCCESS) == 0) {
			if (json_message.getString(SUCCESS_TYPE_KEY).compare(SUCCESS_READING_FILE) == 0) {
				console_writing_mutex.lock();
				wcout << "Successfuly read file" << endl;
				console_writing_mutex.unlock();
			}
			if (json_message.getString(SUCCESS_TYPE_KEY).compare(SUCCESS_ADDING_DATA) == 0) {
				if (json_message.getString(DATA_TYPE_KEY).compare(DATA_OPERATION) == 0) {
					console_writing_mutex.lock();
					wcout << "Successfuly added a new operation" << endl;
					console_writing_mutex.unlock();
					this->handleAddDataSuccessMessage(json_message);
				}
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_SAVE) == 0) {
			if (json_message.getString(SAVE_DATA_KEY).compare(SAVE_TEXT) == 0) {
				this->handleSaveTextMessage(json_message);
			}
			if (json_message.getString(SAVE_DATA_KEY).compare(SAVE_BINARY) == 0) {
				this->handleSaveBinaryMessage(json_message);
			}
		}
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_GET_REPORT) == 0) {
			if (json_message.getString(REPORT_TYPE_KEY).compare(REPORT_STATISTIC) == 0) {
				this->handleGetStatisticMessage(json_message);
			}
		}
	}
	catch (MagicJSON::JsonException e){
		console_writing_mutex.lock();
		wcout << "Error: recieved error type message" << endl;
		console_writing_mutex.unlock();
		MagicJSON::JsonObject answer_json;
		answer_json.addString(COMMAND_TYPE_KEY, COMMAND_ERROR);
		answer_json.addString(ERROR_TYPE_KEY, ERROR_INVALID_COMMAND);
		wstring answer_message = answer_json.toString();
		this->dispatcher->throwMessage(answer_message);
	}
}


void NetworkMessagesHandler::handleSendAllDataMessage(MagicJSON::JsonObject message) {
	ATable::Table* table_extraditions = constructTableForOperations("extraditions");
	ATable::Table* table_returns = constructTableForOperations("returns");

	MagicJSON::JsonArray extraditions = message.getObject(L"value").getArray(L"extraditions");
	MagicJSON::JsonArray returns = message.getObject(L"value").getArray(L"returns");
	
	for (size_t i = 0; i < extraditions.size(); i++) {
		addOperationToTable(extraditions.getObject(i), table_extraditions);
	}
	for (size_t i = 0; i < returns.size(); i++) {
		addOperationToTable(returns.getObject(i), table_returns);
	}

	console_writing_mutex.lock();
	wcout << "extraditions:" << endl;
	table_extraditions->print(cout);
	wcout << "returns:" << endl;
	table_returns->print(cout);
	console_writing_mutex.unlock();

	delete table_extraditions;
	delete table_returns;
}


void NetworkMessagesHandler::handleSaveTextMessage(MagicJSON::JsonObject message) {
	MagicJSON::JsonObject save_data = message.getObject(VALUE_KEY);

	try {
		wofstream file;
		file.exceptions(std::wofstream::failbit | std::wofstream::badbit);
		file.open(FILES_DIRECTORY + message.getString(PATH_KEY) + TEXT_EXTENSION);
		file << save_data.toString();
	}
	catch (wofstream::failure e) {
		console_writing_mutex.lock();
		wcout << "Error: unable to save in file: " << message.getString(PATH_KEY) << endl;
		console_writing_mutex.unlock();
		return;
	}
	console_writing_mutex.lock();
	wcout << "successfully saved file" << endl;
	console_writing_mutex.unlock();
}


void NetworkMessagesHandler::handleSaveBinaryMessage(MagicJSON::JsonObject message) {
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	string base_string = base64_decode(converter.to_bytes(message.getString(VALUE_KEY)));
	size_t size = message.getInteger(SIZE_KEY);
	

	ofstream file;
	try {
		file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
		file.open(FILES_DIRECTORY + message.getString(PATH_KEY) + BINARY_EXTENSION, ios::binary);
	}
	catch (ofstream::failure e) {
		console_writing_mutex.lock();
		wcout << "Error: unable to save in file: " << message.getString(PATH_KEY) << endl;
		console_writing_mutex.unlock();
		return;
	}
	byte* buffer = new byte[size];
	memcpy(buffer, base_string.c_str(), size*sizeof(byte));
	file.write((char*)buffer, size*sizeof(byte));
	delete[] buffer;
	console_writing_mutex.lock();
	wcout << "successfully saved file" << endl;
	console_writing_mutex.unlock();
}


void NetworkMessagesHandler::handleAddDataSuccessMessage(MagicJSON::JsonObject message) {
	ATable::Table* table = constructTableForOperations("new object");
	addOperationToTable(message.getObject(VALUE_KEY), table);
	table->print(cout);
	delete table;
}


void NetworkMessagesHandler::handleGetStatisticMessage(MagicJSON::JsonObject message) {
	ATable::Table* table = new ATable::Table(ATable::DefaultAppearance(), "statistic");
	table->addColumn(new ATable::SimpleColumn("Average films leghth", 30, "film_length"));
	table->addColumn(new ATable::SimpleColumn("Average film names leghth", 30, "name_length"));

	table->addCell("film_length", new ATable::DoubleCell(message.getObject(VALUE_KEY).getFloat(L"average_length")));
	table->addCell("name_length", new ATable::DoubleCell(message.getObject(VALUE_KEY).getFloat(L"average_symbols")));
	console_writing_mutex.lock();
	table->print(cout);
	console_writing_mutex.unlock();
	delete table;
}


void NetworkMessagesHandler::addOperationToTable(MagicJSON::JsonObject operation, ATable::Table* table) {
	wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	table->addCell("operation_year", new ATable::LongCell(operation.getInteger(L"operation_year")));
	table->addCell("operation_month", new ATable::LongCell(operation.getInteger(L"operation_month")));
	table->addCell("operation_day", new ATable::LongCell(operation.getInteger(L"operation_day")));

	table->addCell("abonent_name", new ATable::StringCell(converter.to_bytes(operation.getString(L"abonent_name"))));
	table->addCell("abonent_surename", new ATable::StringCell(converter.to_bytes(operation.getString(L"abonent_surename"))));
	table->addCell("abonent_year", new ATable::LongCell(operation.getInteger(L"abonent_year")));
	table->addCell("abonent_month", new ATable::LongCell(operation.getInteger(L"abonent_month")));

	table->addCell("disk_length", new ATable::LongCell(operation.getInteger(L"disk_length")));
	table->addCell("disk_name", new ATable::StringCell(converter.to_bytes(operation.getString(L"disk_name"))));
	table->addCell("disk_year", new ATable::LongCell(operation.getInteger(L"disk_year")));
	table->addCell("disk_month", new ATable::LongCell(operation.getInteger(L"disk_month")));
	table->addCell("disk_day", new ATable::LongCell(operation.getInteger(L"disk_day")));

	table->addCell("studio_name", new ATable::StringCell(converter.to_bytes(operation.getString(L"studio_name"))));
	table->addCell("studio_year", new ATable::LongCell(operation.getInteger(L"studio_year")));
	table->addCell("studio_month", new ATable::LongCell(operation.getInteger(L"studio_month")));
	table->addCell("studio_day", new ATable::LongCell(operation.getInteger(L"studio_day")));
}


ATable::Table* NetworkMessagesHandler::constructTableForOperations(string name) {
	ATable::Table* table = new ATable::Table(ATable::DefaultAppearance(), name);
	table->addColumn(new ATable::SimpleColumn("OpY", 4, "operation_year"));
	table->addColumn(new ATable::SimpleColumn("OpM", 3, "operation_month"));
	table->addColumn(new ATable::SimpleColumn("OpD", 3, "operation_day"));

	table->addColumn(new ATable::ConstColumn("->", "separator_1"));

	table->addColumn(new ATable::SimpleColumn("Abon name", 10, "abonent_name"));
	table->addColumn(new ATable::SimpleColumn("Abon sname", 10, "abonent_surename"));
	table->addColumn(new ATable::SimpleColumn("AbY", 10, "abonent_year"));
	table->addColumn(new ATable::SimpleColumn("AbM", 10, "abonent_month"));

	table->addColumn(new ATable::SimpleColumn("Disk Len", 8, "disk_length"));
	table->addColumn(new ATable::SimpleColumn("Disk", 10, "disk_name"));
	table->addColumn(new ATable::SimpleColumn("DsY", 4, "disk_year"));
	table->addColumn(new ATable::SimpleColumn("DsM", 3, "disk_month"));
	table->addColumn(new ATable::SimpleColumn("DsD", 3, "disk_day"));

	table->addColumn(new ATable::SimpleColumn("Studio", 10, "studio_name"));
	table->addColumn(new ATable::SimpleColumn("StY", 4, "studio_year"));
	table->addColumn(new ATable::SimpleColumn("StM", 3, "studio_month"));
	table->addColumn(new ATable::SimpleColumn("StD", 3, "studio_day"));

	return table;
}
