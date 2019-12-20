#pragma once
#include "TurboPipes.h"
#include <iostream>

using namespace std;

class TPipeableString :
	public TurboPipes::PipeableString
{
public:
	TPipeableString() {}
	~TPipeableString() {}
	void handleMessage(wstring& message) override {
		wcout << "caught message: " << message << endl;
		this->dispatcher->throwMessage(message);
	}
};


