#pragma once
#include "Object.h"
#include "Fileable.h"
#include "Exception.h"

class Date1 : public Object, public Fileable {
protected:
	short year;
	short month;
public:
	Date1(const short year, const short month);
	Date1() : Date1(2000, 0) {}
	~Date1() {}
	Date1(const Date1& reference);
	short getYear() const;
	void setYear(const short year);
	short getMonth() const;
	void setMonth(const short year);
	virtual void save(ofstream& stream) const;
	virtual void load(ifstream& stream);
};

