#include "BaseClass.h"



BaseClass::BaseClass() : BaseClass(0, 0.0) {}

BaseClass::BaseClass(int integer,float flt) : flt(flt), integer(integer) {}


BaseClass::~BaseClass() {}

void BaseClass::save(ofstream& stream) const {
	size_t nameLength = strlen(typeid(BaseClass).name()) + 1;
	char* name = new char[nameLength];
	strcpy_s(name, nameLength, typeid(BaseClass).name());
	stream.write((char*) & (nameLength), sizeof(size_t));
	stream.write(name, nameLength * sizeof(char));
	delete[] name;
	stream.write((char*) & (this->integer), sizeof(int));
	stream.write((char*) & (this->flt), sizeof(float));
}

void BaseClass::load(ifstream& stream) {
	size_t nameLength = 0;
	stream.read((char*) & (nameLength), sizeof(size_t));
	char* name = new char[nameLength];
	stream.read(name, nameLength * sizeof(char));
	if (strcmp(name, typeid(BaseClass).name()) != 0) {
		throw WrongInputFileException();
	}
	delete[] name;
	stream.read((char*) & (this->integer), sizeof(int));
	stream.read((char*) & (this->flt), sizeof(float));
}
