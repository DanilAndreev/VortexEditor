#include "Abonent.h"

Abonent::Abonent(const Abonent& reference) : Date1(reference), Nameable(reference) {
	this->surename = reference.surename;
}

void Abonent::setSurename(const String surename) {
	this->surename = surename;
}

String Abonent::getSurename() const {
	return this->surename;
}
