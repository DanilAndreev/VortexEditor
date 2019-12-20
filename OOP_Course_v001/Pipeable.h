#pragma once
#include <queue>
#include <string>
#include "Threadable.h"

#include <iostream>

using namespace std;

class PipeDispatcher;

class Pipeable : private Threadable{
private:
	queue<wstring> messages;
protected:
	PipeDispatcher* dispatcher;
public:
	Pipeable();
	~Pipeable();
	void connect(PipeDispatcher* dispatcher);
	void queueMessage(wstring message);
private:
	void threadFunction() override;
	void handler();
public:
	virtual void handleMessage(wstring& message) = 0;
};
