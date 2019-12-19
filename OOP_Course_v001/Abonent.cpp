#include "Abonent.h"

Abonent::Abonent(const Abonent& reference) : Date1(reference), Nameable(reference) {
	this->surename = reference.surename;
}

void Abonent::setSurename(const FWString surename) {
	this->surename = surename;
}

FWString Abonent::getSurename() const {
	return this->surename;
}

void Abonent::save(ofstream& stream) const {
	size_t hash = typeid(Abonent).hash_code();
	stream.write((char*)& hash, sizeof(size_t));
	this->surename.save(stream);
	Date1::save(stream);
}

void Abonent::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*)& hash, sizeof(size_t));
	if (hash != typeid(Abonent).hash_code()) {
		throw WrongInputFileException();
	}
	this->surename.load(stream);
	Date1::load(stream);
}

MagicJSON::JsonObject Abonent::serialize() {
	MagicJSON::JsonObject json;
	json.addString(L"__type", L"abonent");
	json.addInteger(L"__hash", typeid(Abonent).hash_code());
	json.addString(L"name", this->name);
	json.addString(L"surename", this->surename);
	json.addObject(L"date", Date1::serialize());
	return json;
}

void Abonent::deserialize(MagicJSON::JsonObject json) {
	try {
		if (json.getString(L"__type") != L"abonent") {
			throw exception();
		}
		this->name = json.getString(L"name");
		this->surename = json.getString(L"surename");
		Date1::deserialize(json.getObject(L"date"));
	}
	catch (MagicJSON::NoObjectFoundException e) {
		throw exception();
	}
}

void Abonent::operator=(const Abonent& reference) {
	this->surename = reference.surename;
	Date1::operator=(reference);
	Nameable::operator=(reference);
}
