#pragma once
#include <string>
#include "WonderMenuExceptions.h"

using namespace std;

class MenuCommand {
protected:
	wstring key;
	wstring description;
public:
	MenuCommand(wstring key, wstring description);
	virtual ~MenuCommand();
	wstring getKey();
public:
	virtual void handleCommnad(wstring inputData) = 0;
};

