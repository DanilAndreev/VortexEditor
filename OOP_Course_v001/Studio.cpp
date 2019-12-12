#include "Studio.h"

Studio::Studio(const Studio& reference) : Date2(reference) {
	this->name = reference.name;
}

void Studio::setName(const String name) {
	this->name = name;
}

String Studio::getName() const {
	return this->name;
}
