#include "Returnable.h"

Returnable::Returnable(const Returnable& reference) {
	this->isreturn = reference.isreturn;
}

void Returnable::operator=(const Returnable& reference) {
	this->isreturn = reference.isreturn;
}
