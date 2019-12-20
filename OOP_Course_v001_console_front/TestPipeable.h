#pragma once
#include "TurboPipes.h"

#include <iostream>
#include <string>

using namespace std;

class TestPipeable : public TurboPipes::PipeableString {
public:
	TestPipeable() {}
	~TestPipeable() {}
	void handleMessage(wstring& message) override {
		wcout << "recieved: " << message << endl;
	}
};

