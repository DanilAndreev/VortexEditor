#pragma once
#include "Date1.h"
class Date2 : public Date1 {
protected:
	short day;
public:
	Date2(const short year, const short month, const short day); // TODO: Finish exceptions when 31 and 30 days
	Date2() : Date1(), day(0) {}	
	~Date2() {}
	Date2(const Date2& reference);
	short getDay() const;
	void setDay(const short day);
public:
	void save(ofstream & stream) const override;
	void load(ifstream& stream) override;
	MagicJSON::JsonObject serialize() override;
	void deserialize(MagicJSON::JsonObject json) override;
public:
	void operator=(const Date2& reference);
	bool operator> (const Date2& right);
	bool operator< (const Date2& right);
	bool operator>= (const Date2& right);
	bool operator<= (const Date2& right);
	bool operator== (const Date2& right);
};

