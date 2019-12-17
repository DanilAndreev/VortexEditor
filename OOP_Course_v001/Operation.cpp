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

void Operation::save(ofstream& stream) const {
	size_t hash = typeid(Operation).hash_code();
	stream.write((char*)& hash, sizeof(size_t));
	stream.write((char*)& this->isreturn, sizeof(bool));
	this->date.save(stream);
	this->abonent.save(stream);
	this->disk.save(stream);
}

void Operation::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*)& hash, sizeof(size_t));
	if (hash != typeid(Operation).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*)& this->isreturn, sizeof(bool));
	this->date.load(stream);
	this->abonent.load(stream);
	this->disk.load(stream);
}

void Operation::operator=(const Operation& reference) {
	this->date = reference.date;
	this->abonent = reference.abonent;
	this->disk = reference.disk;
}
