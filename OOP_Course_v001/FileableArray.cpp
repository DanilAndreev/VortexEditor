#include "FileableArray.h"




FileableArray::~FileableArray()
{
}

void FileableArray::save(ofstream& stream) const {
	size_t hash = typeid(FileableArray).hash_code();
	stream.write((char*)&(hash), sizeof(size_t));
	stream.write((char*) & (this->len), sizeof(size_t));
	for (size_t i = 0; i < this->len; i++) {
		this->get(i)->save(stream);
	}
}

void FileableArray::load(ifstream& stream) {
	this->clear();
	size_t hash = 0;
	stream.read((char*)&(hash), sizeof(size_t));
	if (hash != typeid(FileableArray).hash_code()) {
		throw WrongInputFileException();
	}
	size_t quantity = 0;
	stream.read((char*) & (quantity), sizeof(size_t));
	for (int i = 0; i < quantity; i++) {
		size_t hash = 0;
		stream.read((char*) & (hash), sizeof(size_t));
		Fileable* object = nullptr;
		for (size_t i = 0; i < this->types.size(); i++) {
			Fileable* temp = this->types.get(i)(hash);
			if (temp) {
				object = temp;
				break;
			}
		}
		stream.seekg((-1) * (long)sizeof(size_t), ios::cur);
		if (object) {
			object->load(stream);
		}
		else {
			throw UnknownDataTypeException();
		}
		this->add(object);
	}
}

void FileableArray::addLoadableType(Fileable*(*callback)(size_t hash)) {
	this->types.add(callback);
}
