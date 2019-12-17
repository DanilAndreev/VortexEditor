#pragma once
#include "String.h"
#include "FWString.h"

class Nameable {
protected:
	FWString name;
public:
	Nameable(const FWString name) : name(name) {}
	Nameable() : Nameable(L"") {}
	Nameable(const Nameable& reference) {
		this->name = reference.name;
	}
	~Nameable() {}
	void setName(const FWString name) {
		this->name = name;
	}
	FWString getName() const {
		return this->name;
	}
public:
	void operator= (const Nameable& reference);
};

