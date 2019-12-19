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
	size_t hash = typeid(FVector).hash_code();
	stream.write((char*) & (hash), sizeof(size_t));
	size_t quantity = this->size();
	stream.write((char*) & (quantity), sizeof(size_t));
	for (size_t i = 0; i < quantity; i++) {
		this->get(i)->save(stream);
	}
}


void FVector::load(ifstream& stream) {
	this->clear();
	size_t hash = 0;
	stream.read((char*) & (hash), sizeof(size_t));
	if (hash != typeid(FVector).hash_code()) {
		throw WrongInputFileException();
	}
	size_t quantity = 0;
	stream.read((char*) & (quantity), sizeof(size_t));
	for (size_t i = 0; i < quantity; i++) {
		size_t hash = 0;
		stream.read((char*) & (hash), sizeof(size_t));
		Fileable* object = nullptr;
		try {
			object = this->creators.get(hash)();
		}
		catch (NoObjectFoundException e) {
			throw UnknownDataTypeException();
		}
		stream.seekg((-1) * (long)sizeof(size_t), ios::cur);
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
