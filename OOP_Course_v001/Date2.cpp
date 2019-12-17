#include "Date2.h"

Date2::Date2(const short year, const short month, const short day) : Date1(year, month) {
	this->setDay(day);
}

Date2::Date2(const Date2& reference) : Date1(reference) {
	this->day = reference.day;
}

short Date2::getDay() const {
	return this->day;
}

void Date2::setDay(const short day) {
	if (day < 0 || day > 31) {
		throw WrongInputValuesException();
	}
	if (this->month % 2 && day > 30) {
		throw WrongInputValuesException();
	}
	if (this->month == 11 && (day > 28)) {
		throw WrongInputValuesException();
	}
	this->day = day;
}

void Date2::save(ofstream& stream) const {
	size_t hash = typeid(Date2).hash_code();
	stream.write((char*)&hash, sizeof(size_t));
	stream.write((char*) & (this->day), sizeof(short));
	Date1::save(stream);
}

void Date2::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*)&hash, sizeof(size_t));
	if (hash != typeid(Date2).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*) & (this->day), sizeof(short));
	Date1::load(stream);
}

void Date2::operator=(const Date2& reference) {
	this->day = reference.day;
	Date1::operator=(reference);
}
