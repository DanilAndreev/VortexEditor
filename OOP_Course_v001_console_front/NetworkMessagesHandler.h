#pragma once
#include "TurboPipes.h"
#include <string>
#include <iostream>

using namespace std;

class NetworkMessagesHandler : public TurboPipes::PipeableString {
public:
	NetworkMessagesHandler();
	~NetworkMessagesHandler();
public:
	void handleMessage(wstring& message) override;
};

