#include "MenuCommandStat.h"
#include <iterator>
#include <sstream>
#include <vector>



MenuCommandStat::MenuCommandStat(TurboPipes::PipeDispatcherString* dispatcher) :
	WMenu::MenuCommand(L"stat", L"Returns statistic"), dispatcher(dispatcher) {
	if (!this->dispatcher) {
		throw exception();
	}
}


MenuCommandStat::~MenuCommandStat() {}


void MenuCommandStat::handleCommnad(wstring inputData) {
	wistringstream iss(inputData);
	vector<wstring> tokens((istream_iterator<wstring, wchar_t>(iss)), istream_iterator<wstring, wchar_t>());

	MagicJSON::JsonObject json_message;
	json_message.addString(COMMAND_TYPE_KEY, COMMAND_GET_REPORT);
	json_message.addString(REPORT_TYPE_KEY, REPORT_STATISTIC);
	wstring string_message = json_message.toString();
	this->dispatcher->throwMessage(string_message);
}
