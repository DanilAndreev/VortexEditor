#pragma once
#include "Date2.h"
#include "String.h"

class Studio : public Date2 {
protected:
	String name;
public:
	Studio(const String name, const short year, const short month, const short day) : Date2(year, month, day), name(name) {}
	Studio() : Date2(), name("") {}
	~Studio() {}
	Studio(const Studio& reference);

	void setName(const String name);
	String getName() const;
};

