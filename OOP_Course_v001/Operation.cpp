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
	hash_code hash = (hash_code)typeid(Operation).hash_code();
	stream.write((char*)& hash, sizeof(hash_code));
	stream.write((char*)& this->isreturn, sizeof(bool));
	this->date.save(stream);
	this->abonent.save(stream);
	this->disk.save(stream);
}

void Operation::load(ifstream& stream) {
	hash_code hash = 0;
	stream.read((char*)& hash, sizeof(hash_code));
	if (hash != (hash_code)typeid(Operation).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*)& this->isreturn, sizeof(bool));
	this->date.load(stream);
	this->abonent.load(stream);
	this->disk.load(stream);
}

MagicJSON::JsonObject Operation::serialize() {
	MagicJSON::JsonObject json;
	json.addString(L"__type", L"operation");
	json.addInteger(L"__hash", typeid(Operation).hash_code());
	json.addObject(L"date", this->date.serialize());
	json.addObject(L"abonent", this->abonent.serialize());
	json.addObject(L"disk", this->disk.serialize());
	json.addInteger(L"is_return", (long)(this->isreturn));
	return json;
}

void Operation::deserialize(MagicJSON::JsonObject json) {
	try {
		if (json.getString(L"__type") != L"operation") {
			throw UnexpectedTypeException();
		}
		this->date.deserialize(json.getObject(L"date"));
		this->abonent.deserialize(json.getObject(L"abonent"));
		this->disk.deserialize(json.getObject(L"disk"));
		this->isreturn = (bool)json.getInteger(L"is_return");
	}
	catch (MagicJSON::NoObjectFoundException e) {
		throw IncorrectObjectDataException();
	}
}

void Operation::operator=(const Operation& reference) {
	this->date = reference.date;
	this->abonent = reference.abonent;
	this->disk = reference.disk;
}
