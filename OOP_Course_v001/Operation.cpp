#include "Operation.h"

Operation::Operation(const Operation& reference) {
	this->date = reference.date;
	this->abonent = reference.abonent;
	this->disk = reference.disk;
}

void Operation::setDate(const Date2 date) {
	this->date = date;
}

Date2 Operation::getDate() const {
	return this->date;
}

void Operation::setAbonent(const Abonent abonent) {
	this->abonent = abonent;
}

Abonent Operation::getAbonent() const {
	return this->abonent;
}

void Operation::setDisk(const Disk disk) {
	this->disk = disk;
}

Disk Operation::getDisk() const {
	return this->disk;
}
