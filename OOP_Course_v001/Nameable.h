#pragma once
#include "String.h"

class Nameable {
protected:
	String name;
public:
	Nameable(const String name) : name(name) {}
	Nameable() : Nameable("") {}
	~Nameable() {}
	Nameable(const Nameable & reference) {
		this->name = name;
	}
	void setName(const String name) {
		this->name = name;
	}
	String getName() const {
		return this->name;
	}
};

