#pragma once
#include "Date2.h"
//#include "FWString.h"
#include "Nameable.h"

class Studio : public Date2, public Nameable{
public:
	Studio(const FWString name, const short year, const short month, const short day) : Date2(year, month, day), Nameable(name) {}
	Studio() : Date2(), Nameable(L"") {}
	Studio(const Studio& reference);
	~Studio() {}

	virtual void save(ofstream& stream) const override;
	virtual void load(ifstream& stream) override;
public:
	void operator= (const Studio& reference);
};
