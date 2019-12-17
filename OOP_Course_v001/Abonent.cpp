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

void Abonent::operator=(const Abonent& reference) {
	this->surename = reference.surename;
	Date1::operator=(reference);
	Nameable::operator=(reference);
}
