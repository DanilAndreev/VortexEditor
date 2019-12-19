#include "Studio.h"

Studio::Studio(const Studio& reference) : Date2(reference), Nameable(reference){
	//this->name = reference.name;
}

void Studio::save(ofstream& stream) const {
	hash_code hash = (hash_code)typeid(Studio).hash_code();
	stream.write((char*)& hash, sizeof(hash_code));
	Date2::save(stream);
	this->name.save(stream);
}

void Studio::load(ifstream& stream) {
	hash_code hash = 0;
	stream.read((char*)& hash, sizeof(hash_code));
	if (hash != (hash_code)typeid(Studio).hash_code()) {
		throw WrongInputFileException();
	}
	Date2::load(stream);
	this->name.load(stream);
}

MagicJSON::JsonObject Studio::serialize() {
	MagicJSON::JsonObject json;
	json.addString(L"__type", L"studio");
	json.addInteger(L"__hash", typeid(Studio).hash_code());
	json.addObject(L"date", Date2::serialize());
	json.addString(L"name", this->name);
	return json;
}

void Studio::deserialize(MagicJSON::JsonObject json) {
	try {
		if (json.getString(L"__type") != L"studio") {
			throw UnexpectedTypeException();
		}
		this->name = json.getString(L"name");
		Date2::deserialize(json.getObject(L"date"));
	}
	catch (MagicJSON::NoObjectFoundException e) {
		throw IncorrectObjectDataException();
	}
}

void Studio::operator=(const Studio& reference) {
	Date2::operator=(reference);
	Nameable::operator=(reference);
}
