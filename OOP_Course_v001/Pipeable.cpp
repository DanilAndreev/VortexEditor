#include "Pipeable.h"

Pipeable::Pipeable() : Threadable() {}

Pipeable::~Pipeable() {}

void Pipeable::threadFunction() {
	this->handler();
}

void Pipeable::handler() {
	while (true) {
		if (this->messages.empty()) {
			Sleep(10);
		}
		else {
			wstring message = this->messages.back();
			this->messages.pop();
			this->handleMessage(message);
		}
	}
}
