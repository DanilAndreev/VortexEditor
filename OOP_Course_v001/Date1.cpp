#include "Date1.h"

Date1::Date1(const short year, const short month) : Object() {
	if (year < 0 || month <= 0 || month > 12) {
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
	hash_code hash = (hash_code)typeid(Date1).hash_code();
	stream.write((char*)&hash, sizeof(hash_code));
	stream.write((char*)&(this->year), sizeof(short));
	stream.write((char*)&(this->month), sizeof(short));
}

void Date1::load(ifstream& stream) {
	hash_code hash = 0;
	stream.read((char*) & hash, sizeof(hash_code));
	if (hash != (hash_code)typeid(Date1).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*) & (this->year), sizeof(short));
	stream.read((char*) & (this->month), sizeof(short));
}

MagicJSON::JsonObject Date1::serialize() {
	MagicJSON::JsonObject json;
	json.addString(L"__type", L"date");
	json.addInteger(L"__hash", typeid(Date1).hash_code());
	json.addInteger(L"month", (long)this->month);
	json.addInteger(L"year", (long)this->year);
	return json;
}

void Date1::deserialize(MagicJSON::JsonObject json) {
	try {
		if (json.getString(L"__type") != L"date") {
			throw exception();
		}
		this->month = (short)json.getInteger(L"month");
		this->year = (short)json.getInteger(L"year");
	}
	catch (MagicJSON::NoObjectFoundException e){
		throw exception();
	}
}


void Date1::operator=(const Date1& reference) {
	this->year = reference.year;
	this->month = reference.month;
}
