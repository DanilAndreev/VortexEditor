#include "FVector.h"


FVector::FVector(const FVector& reference) : vector<Fileable*>(reference), Fileable(reference), Object(reference) {
	this->creators = reference.creators;
}

Fileable* FVector::get(size_t index) const {
	if (index < 0 || index >= this->size()) {
		throw IndexOutOfBoundsException();
	}
	return (*this)[index];
}


void FVector::save(ofstream& stream) const {
	hash_code hash = (hash_code)typeid(FVector).hash_code();
	stream.write((char*) & (hash), sizeof(hash_code));
	size_t quantity = this->size();
	stream.write((char*) & (quantity), sizeof(size_t));
	for (size_t i = 0; i < quantity; i++) {
		this->get(i)->save(stream);
	}
}


void FVector::load(ifstream& stream) {
	this->clear();
	hash_code hash = 0;
	stream.read((char*) & (hash), sizeof(hash_code));
	if (hash != (hash_code)typeid(FVector).hash_code()) {
		throw WrongInputFileException();
	}
	size_t quantity = 0;
	stream.read((char*) & (quantity), sizeof(size_t));
	for (size_t i = 0; i < quantity; i++) {
		hash_code hash = 0;
		stream.read((char*) & (hash), sizeof(hash_code));
		Fileable* object = nullptr;
		try {
			object = this->creators.get(hash)();
		}
		catch (NoObjectFoundException e) {
			throw UnknownDataTypeException();
		}
		stream.seekg((-1) * (long)sizeof(hash_code), ios::cur);
		object->load(stream);
		this->push_back(object);
	}
}

void FVector::addObjectCreator(size_t hash, Fileable* (*creator)(void)) {
	this->creators.add(hash, creator);
}

Fileable* (*FVector::getObjectCreator(size_t hash))(void) {
	return this->creators.get(hash);
}

void FVector::operator=(const FVector& reference) {
	vector<Fileable*>::operator=(reference);
	this->creators = reference.creators;
}
