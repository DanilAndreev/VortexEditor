#include "NetworkMessagesHandler.h"
#include <locale>
#include <codecvt>


NetworkMessagesHandler::NetworkMessagesHandler()
{
}


NetworkMessagesHandler::~NetworkMessagesHandler()
{
}

void NetworkMessagesHandler::handleMessage(wstring& message) {
	try {
		//wcout << "recieved: " << message << endl;
		MagicJSON::JsonObject json_message(message);
		if (json_message.getString(COMMAND_TYPE_KEY).compare(COMMAND_SEND_DATA) == 0) {
			this->handleSendAllDataMessage(json_message);
		}
	}
	catch (MagicJSON::JsonException e){
		wcout << "Error: recieved error type message" << endl;
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

	wcout << "extraditions:" << endl;
	table_extraditions->print(cout);
	wcout << "returns:" << endl;
	table_returns->print(cout);

	delete table_extraditions;
	delete table_returns;
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
