#pragma once
#include "Date1.h"
#include "Nameable.h"
#include "FWString.h"

class Abonent : public Date1, public Nameable{
protected:
	FWString surename;
public:
	Abonent(const FWString firstname, const FWString surname, const short year, const short month) : Date1(year, month), Nameable(firstname), surename(surename) {}
	Abonent() : Date1(), Nameable(), surename(L"") {}
	Abonent(const Abonent& reference);
	~Abonent() {}
	void setSurename(const FWString surename);
	FWString getSurename() const;
	virtual void save(ofstream& stream) const override;
	virtual void load(ifstream& stream) override;
public:
	void operator=(const Abonent& reference);
};
