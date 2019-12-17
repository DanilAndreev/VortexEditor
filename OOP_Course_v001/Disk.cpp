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
	size_t hash = typeid(Disk).hash_code();
	stream.write((char*)&hash, sizeof(size_t));
	stream.write((char*) & (this->length), sizeof(unsigned int));

	this->studio.save(stream);
	Date2::save(stream);
	this->name.save(stream);
}

void Disk::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*)&hash, sizeof(size_t));
	if (hash != typeid(Disk).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*) & (this->length), sizeof(unsigned int));
	this->studio.load(stream);
	Date2::load(stream);
	this->name.load(stream);
}

void Disk::operator=(const Disk& reference) {
	this->length = reference.length;
	this->studio = reference.studio;
	Date2::operator=(reference);
	Nameable::operator=(reference);
}
