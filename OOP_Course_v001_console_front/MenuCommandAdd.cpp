#include "MenuCommandAdd.h"
#include "InputChecker.h"
#include <iterator>
#include <sstream>
#include <vector>


MenuCommandAdd::MenuCommandAdd(TurboPipes::PipeDispatcherString* dispatcher) :
	WMenu::MenuCommand(L"add", L"Adds an operations to table"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandAdd::~MenuCommandAdd() {}

void MenuCommandAdd::handleCommnad(wstring inputData) {
	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());

	wstring operation_type;
	try {
		if (tokens.size() != 3 || tokens[1].compare(L"operation") != 0) {
			wcout << "invalid arguments" << endl;
			wcout << "usage: add operation [operation_type]" << endl;
			return;
		}
		if (tokens[2].compare(L"return") == 0) {
			operation_type = L"return";
		}
		if (tokens[2].compare(L"extradition") == 0) {
			operation_type = L"extradition";
		}
		if (tokens[2].compare(L"return") != 0 && tokens[2].compare(L"extradition") != 0) {
			wcout << "invalid arguments" << endl;
			wcout << "usage: add operation [operation_type]" << endl;
			return;
		}
	}
	catch (out_of_range e){
		wcout << "invalid arguments" << endl;
		wcout << "usage: add operation [operation_type]" << endl;
		return;
	}

	wcout << "input operation day:" << endl;
	int operation_day = stoi(queryInput(&isDay, INCORRECT_DAY_MSG));
	wcout << "input operation month:" << endl;
	int operation_month = stoi(queryInput(&isMonth, INCORRECT_MONTH_MSG));
	wcout << "input operation year:" << endl;
	int operation_year = stoi(queryInput(&isInteger, INCORRECT_YEAR_MSG));


	wcout << "input abonent name:" << endl;
	wstring abonent_name = queryInput(&isName, INCORRECT_NAME_MSG);
	wcout << "input abonent surename:" << endl;
	wstring abonent_surename = queryInput(&isName, INCORRECT_NAME_MSG);
	wcout << "input abonent birth month:" << endl;
	int abonent_month = stoi(queryInput(&isMonth, INCORRECT_MONTH_MSG));
	wcout << "input abonent birth year:" << endl;
	int abonent_year = stoi(queryInput(&isInteger, INCORRECT_YEAR_MSG));

	wcout << "input disk length:" << endl;
	int disk_length = stoi(queryInput(&isInteger, INCORRECT_NUMBER_MSG));
	wcout << "input disk name:" << endl;
	wstring disk_name = queryInput(&isName, INCORRECT_NAME_MSG);
	wcout << "input disk day:" << endl;
	int disk_day = stoi(queryInput(&isDay, INCORRECT_DAY_MSG));
	wcout << "input disk month:" << endl;
	int disk_month = stoi(queryInput(&isMonth, INCORRECT_MONTH_MSG));
	wcout << "input disk year:" << endl;
	int disk_year = stoi(queryInput(&isInteger, INCORRECT_YEAR_MSG));

	wcout << "input studio name:" << endl;
	wstring studio_name = queryInput(&isName, INCORRECT_NAME_MSG);
	wcout << "input studio day:" << endl;
	int studio_day = stoi(queryInput(&isDay, INCORRECT_DAY_MSG));
	wcout << "input studio month:" << endl;
	int studio_month = stoi(queryInput(&isMonth, INCORRECT_MONTH_MSG));
	wcout << "input studio year:" << endl;
	int studio_year = stoi(queryInput(&isInteger, INCORRECT_NAME_MSG));

	MagicJSON::JsonObject json;
	json.addString(L"operation_type", operation_type);

	json.addInteger(L"operation_day", operation_day);
	json.addInteger(L"operation_month", operation_month);
	json.addInteger(L"operation_year", operation_year);
	json.addString(L"abonent_name", abonent_name);
	json.addString(L"abonent_surename", abonent_surename);
	json.addInteger(L"abonent_month", abonent_month);
	json.addInteger(L"abonent_year", abonent_year);
	json.addInteger(L"disk_length", disk_length);
	json.addString(L"disk_name", disk_name);
	json.addInteger(L"disk_day", disk_day);
	json.addInteger(L"disk_month", disk_month);
	json.addInteger(L"disk_year", disk_year);
	json.addString(L"studio_name", studio_name);
	json.addInteger(L"studio_day", studio_day);
	json.addInteger(L"studio_month", studio_month);
	json.addInteger(L"studio_year", studio_year);
	
	MagicJSON::JsonObject json_message;
	
	json_message.addString(COMMAND_TYPE_KEY, COMMAND_ADD_DATA);
	json_message.addString(DATA_TYPE_KEY, DATA_OPERATION);
	json_message.addObject(VALUE_KEY, json);

	wstring string_message = json_message.toString();
	this->dispatcher->throwMessage(string_message);
}
