#pragma once
#include "Date1.h"
#include "Nameable.h"

class Abonent : public Date1, public Nameable{
protected:
	String surename;
public:
	Abonent(const String surname) : surename(surename) {}
	Abonent() : Abonent("") {}
	~Abonent() {}
	Abonent(const Abonent& reference);
	void setSurename(const String surename);
	String getSurename() const;
};
