#pragma once
#include "Returnable.h"
#include "Abonent.h"
#include "Date2.h"
#include "Disk.h"

class Operation : public Returnable {
protected:
	Date2 date;
	Abonent abonent;
	Disk disk;
public:
	Operation(Date2 date, Abonent abonent, Disk disk, bool isreturn) : Returnable(isreturn), date(date), abonent(abonent), disk(disk) {}
	Operation() : Returnable(), date(Date2()), abonent(Abonent()), disk(Disk()) {}
	~Operation() {}
	Operation(const Operation & reference);
	void setDate(const Date2 date);
	Date2 getDate() const;
	void setAbonent(const Abonent abonent);
	Abonent getAbonent() const;
	void setDisk(const Disk disk);
	Disk getDisk() const;
};

