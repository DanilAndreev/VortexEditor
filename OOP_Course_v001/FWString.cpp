#include "FWString.h"

void FWString::save(ofstream& stream) const {
	size_t hash = typeid(FWString).hash_code();
	stream.write((char*) & (hash), sizeof(size_t));
	size_t length = this->length() + 1;
	stream.write((char*) & (length), sizeof(size_t));
	LPCWSTR str = this->c_str();
	stream.write((char*)str, length*sizeof(WCHAR));
}

void FWString::load(ifstream& stream) {
	this->clear();
	size_t hash = 0;
	stream.read((char*) & (hash), sizeof(size_t));
	if (hash != typeid(FWString).hash_code()) {
		throw WrongInputFileException();
	}
	size_t length = 0;
	stream.read((char*) & (length), sizeof(size_t));
	LPCWSTR str = new WCHAR[length];
	stream.read((char*)str, length*sizeof(WCHAR));
	this->append(str);
	delete[] str;
}
