#pragma once
#include <windows.h>
#include <string>
#include "Pipeable.h"
using namespace std;

class PipeDispatcher {
private:
	HANDLE hNamedPipe;
	DWORD cbWritten;
	DWORD cbRead;
	wstring szBuf;
	wstring pipeName;

	bool is_server;
protected:
	Pipeable* object;
public:
	PipeDispatcher(wstring szPipeName, bool is_server);
	~PipeDispatcher();
	void throwMessage(wstring message);
	wstring catchMessage();

};

