#pragma once
#include <queue>
#include <string>
#include "Threadable.h"

using namespace std;

class Pipeable : private Threadable{
private:
	queue<wstring> messages;
public:
	Pipeable();
	~Pipeable();
private:
	void threadFunction() override;
	void handler();
public:
	virtual void _stdcall handleMessage(wstring& message) {}
};

