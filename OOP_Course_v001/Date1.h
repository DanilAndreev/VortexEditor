#pragma once
#include "Object.h"
#include "Fileable.h"
#include "Exception.h"
#include "Serializeable.h"

class Date1 : public Object, public Fileable, public Serializeable {
protected:
	short year;
	short month;
public:
	Date1(const short year, const short month);
	Date1() : Date1(2000, 1) {}
	~Date1() {}
	Date1(const Date1& reference);
	short getYear() const;
	void setYear(const short year);
	short getMonth() const;
	void setMonth(const short year);
public:
	void save(ofstream& stream) const override;
	void load(ifstream& stream) override;
	MagicJSON::JsonObject serialize() override;
	void deserialize(MagicJSON::JsonObject json) override;
public:
	void operator= (const Date1& reference);
};
