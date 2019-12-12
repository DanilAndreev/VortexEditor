#include "Date1.h"

Date1::Date1(const short year, const short month) : Object() {
	if (year < 0 || month < 0 || month > 11) {
		throw WrongInputValuesException();
	}
	this->year = year;
	this->month = month;
}

Date1::Date1(const Date1& reference) : Object(reference) {
	this->year = reference.year;
	this->month = reference.month;
}

short Date1::getYear() const {
	return this->year;
}

void Date1::setYear(const short year) {
	if (year < 0) {
		throw WrongInputValuesException();
	}
	this->year = year;
}

short Date1::getMonth() const {
	return this->month;
}

void Date1::setMonth(const short month) {
	if (month < 0 || month > 11) {
		throw WrongInputValuesException();
	}
	this->month = month;
}

void Date1::save(ofstream& stream) const {
	size_t hash = typeid(Date1).hash_code();
	stream.write((char*)&hash, sizeof(size_t));
	stream.write((char*)&(this->year), sizeof(short));
	stream.write((char*)&(this->month), sizeof(short));
}

void Date1::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*) & hash, sizeof(size_t));
	if (hash != typeid(Date1).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*) & (this->year), sizeof(short));
	stream.read((char*) & (this->month), sizeof(short));
}
