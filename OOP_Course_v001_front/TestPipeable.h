#pragma once
#include "TurboPipes.h"

class TestPipeable : public Pipeable {
public:
	TestPipeable();
	~TestPipeable() {}
	void handleMessage(wstring& message) override;
};

