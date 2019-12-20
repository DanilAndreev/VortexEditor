#include "PipeDispatcher.h"

PipeDispatcher::PipeDispatcher(wstring szPipeName, bool is_server) {
	this->is_server = is_server;
	if (this->is_server) {
		hNamedPipe = CreateNamedPipe(
			this->pipeName.c_str(),
			PIPE_ACCESS_DUPLEX,
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
			PIPE_UNLIMITED_INSTANCES,
			1024, 1024, 5000, NULL);
		if (hNamedPipe == INVALID_HANDLE_VALUE) {
			throw exception();
		}
		BOOL fConnected = ConnectNamedPipe(hNamedPipe, NULL);
		if (!fConnected) {
			switch (GetLastError()) {
			case ERROR_NO_DATA:
				fprintf(stdout, "ConnectNamedPipe: ERROR_NO_DATA");
				CloseHandle(hNamedPipe);
				break;

			case ERROR_PIPE_CONNECTED:
				fprintf(stdout,
					"ConnectNamedPipe: ERROR_PIPE_CONNECTED");
				CloseHandle(hNamedPipe);
				break;

			case ERROR_PIPE_LISTENING:
				fprintf(stdout,
					"ConnectNamedPipe: ERROR_PIPE_LISTENING");
				CloseHandle(hNamedPipe);
				break;

			case ERROR_CALL_NOT_IMPLEMENTED:
				fprintf(stdout,
					"ConnectNamedPipe: ERROR_CALL_NOT_IMPLEMENTED");
				CloseHandle(hNamedPipe);
				break;

			default:
				fprintf(stdout, "ConnectNamedPipe: Error %ld\n",
					GetLastError());
				CloseHandle(hNamedPipe);
				break;

			}
		}
	}
	else {

	}
}

PipeDispatcher::~PipeDispatcher() {
	CloseHandle(this->hNamedPipe);
}

wstring PipeDispatcher::catchMessage() {
	wchar_t buff[1024];
	wstring buffer;
	if (ReadFile(hNamedPipe, buff, 1024, &cbRead, NULL)) {

	}

	return wstring();
}
