#pragma once
#include "Date1.h"
#include "Nameable.h"
#include "FWString.h"

class Abonent : public Date1, public Nameable{
protected:
	FWString surename;
public:
	Abonent(const FWString firstname, const FWString surename, const short year, const short month) : Date1(year, month), Nameable(firstname), surename(surename) {}
	Abonent() : Date1(), Nameable(), surename(L"") {}
	Abonent(const Abonent& reference);
	~Abonent() {}
	void setSurename(const FWString surename);
	FWString getSurename() const;
public:
	void save(ofstream& stream) const override;
	void load(ifstream& stream) override;
	MagicJSON::JsonObject serialize() override;
	void deserialize(MagicJSON::JsonObject json) override;
public:
	void operator=(const Abonent& reference);
};
