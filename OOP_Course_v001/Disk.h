#pragma once
#include "Date2.h"
#include "String.h"
#include "Studio.h"
#include "Nameable.h"


class Disk : public Date2, public Nameable {
protected:
	unsigned int length;
	Studio studio;
public:
	Disk(const Studio studio, const unsigned int length, const FWString name, const short year, const short month, const short day) :
		Date2(year, month, day), Nameable(name), studio(studio), length(length) {}
	Disk() : Date2(), Nameable(), length(0), studio(Studio()) {}
	Disk(const Disk& reference);
	~Disk() {}
	void setLength(const unsigned int length);
	unsigned int getLength() const;
	void setStudio(const Studio studio);
	Studio getStudio() const;
	virtual void save(ofstream& stream) const override;
	virtual void load(ifstream& stream) override;
public:
	void operator= (const Disk& reference);
};

