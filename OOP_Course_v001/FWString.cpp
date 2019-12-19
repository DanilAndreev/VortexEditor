#include "FWString.h"

void FWString::save(ofstream& stream) const {
	hash_code hash = (hash_code)typeid(FWString).hash_code();
	stream.write((char*) & (hash), sizeof(hash_code));
	size_t length = this->length() + 1;
	stream.write((char*) & (length), sizeof(size_t));
	LPCWSTR str = this->c_str();
	stream.write((char*)str, length*sizeof(WCHAR));
}

void FWString::load(ifstream& stream) {
	this->clear();
	hash_code hash = 0;
	stream.read((char*) & (hash), sizeof(hash_code));
	if (hash != (hash_code)typeid(FWString).hash_code()) {
		throw WrongInputFileException();
	}
	size_t length = 0;
	stream.read((char*) & (length), sizeof(size_t));
	LPCWSTR str = new WCHAR[length];
	stream.read((char*)str, length*sizeof(WCHAR));
	this->append(str);
	delete[] str;
}
