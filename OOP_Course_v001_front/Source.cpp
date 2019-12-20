#include "MagicJSON.h"
#include "TurboPipes.h"
#include "TestPipeable.h"

PipeDispatcher* dispatcher;

void startup() {
	TestPipeable* pip = new TestPipeable();
	dispatcher = new PipeDispatcher(L"\\\\.\\pipe\\$MyPipe$", false, pip);
}