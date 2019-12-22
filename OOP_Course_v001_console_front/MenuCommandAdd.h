#pragma once
#include "WMenu.h"
#include "TurboPipes.h"
#include "MagicJSON.h"
#include "NetworkMessageKeys.h"
#include <iostream>
#include <string>

using namespace std;

const LPCWSTR INCORRECT_DAY_MSG = L"Incorrect day, enter integer mote than 0 and less or equal 31";
const LPCWSTR INCORRECT_MONTH_MSG = L"Incorrect month, enter integer mote than 0 and less or equal 12";
const LPCWSTR INCORRECT_YEAR_MSG = L"Incorrect year, enter integer value";
const LPCWSTR INCORRECT_NUMBER_MSG = L"Incorrect number, enter integer value";
const LPCWSTR INCORRECT_NAME_MSG = L"Incorrect name, first letter should be capital";

class MenuCommandAdd : public WMenu::MenuCommand {
protected:
	TurboPipes::PipeDispatcherString* dispatcher;
public:
	MenuCommandAdd(TurboPipes::PipeDispatcherString* dispatcher);
	~MenuCommandAdd();
public:
	void handleCommnad(wstring inputData) override;
};

