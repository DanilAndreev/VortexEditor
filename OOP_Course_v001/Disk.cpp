#include "Disk.h"

Disk::Disk(const Disk& reference) : Date2(reference), Nameable(reference) {
	this->studio = reference.studio;
	this->length = reference.length;
}

void Disk::setLength(const unsigned int length) {
	this->length = length;
}

unsigned int Disk::getLength() const {
	return this->length;
}

void Disk::setStudio(const Studio studio) {
	this->studio = studio;
}

Studio Disk::getStudio() const {
	return this->studio;
}

void Disk::save(ofstream& stream) const {
	hash_code hash = (hash_code)typeid(Disk).hash_code();
	stream.write((char*)&hash, sizeof(hash_code));
	stream.write((char*) & (this->length), sizeof(unsigned int));

	this->studio.save(stream);
	Date2::save(stream);
	this->name.save(stream);
}

void Disk::load(ifstream& stream) {
	hash_code hash = 0;
	stream.read((char*)&hash, sizeof(hash_code));
	if (hash != (hash_code)typeid(Disk).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*) & (this->length), sizeof(unsigned int));
	this->studio.load(stream);
	Date2::load(stream);
	this->name.load(stream);
}

MagicJSON::JsonObject Disk::serialize() {
	MagicJSON::JsonObject json;
	json.addString(L"__type", L"disk");
	json.addInteger(L"__hash", typeid(Disk).hash_code());
	json.addObject(L"date", Date2::serialize());
	json.addString(L"name", this->name);
	json.addInteger(L"length", this->length);
	json.addObject(L"studio", this->studio.serialize());
	return json;
}

void Disk::deserialize(MagicJSON::JsonObject json) {
	try {
		if (json.getString(L"__type") != L"disk") {
			throw exception();
		}
		this->name = json.getString(L"name");
		this->length = json.getInteger(L"length");
		Date2::deserialize(json.getObject(L"date"));
		this->studio.deserialize(json.getObject(L"studio"));
	}
	catch (MagicJSON::NoObjectFoundException e) {
		throw exception();
	}
}

void Disk::operator=(const Disk& reference) {
	this->length = reference.length;
	this->studio = reference.studio;
	Date2::operator=(reference);
	Nameable::operator=(reference);
}
