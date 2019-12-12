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
	size_t hash = typeid(Date2).hash_code();
	stream.write((char*)&hash, sizeof(size_t));
	stream.write((char*) & (this->length), sizeof(unsigned int));

	size_t nameLength = this->name.length() + 1;
	stream.write((char*) & nameLength, sizeof(size_t));
	const char* c_name = this->name.c_str();
	stream.write(c_name, nameLength*sizeof(char));
	delete[] c_name;
	this->studio.save(stream);
	Date2::save(stream);
}

void Disk::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*)&hash, sizeof(size_t));
	if (hash != typeid(Date1).hash_code()) {
		throw WrongInputFileException();
	}
	stream.read((char*) & (this->length), sizeof(unsigned int));
	size_t nameLength = 0;
	stream.read((char*)&nameLength, sizeof(size_t));
	char* name = new char[nameLength];
	stream.read(name, nameLength*sizeof(char));
	this->name = String(name);
	delete[] name;
	this->studio.load(stream);
	Date2::load(stream);
}
