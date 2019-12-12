#include "String.h"
#include "String.h"

String::String(const char* str) : ArrayList<char>(){
	this->len = strlen(str) + 1;
	this->data = new char*[this->len];
	//memcpy(this->data, str, (len-1)*sizeof(char));
	for (int i = 0; i < this->len - 1; i++) {
		this->data[i] = new char;
		*(this->data[i]) = str[i];
	}
	this->data[this->len - 1] = new char;
	*(this->data[this->len-1]) = '\0';
}

String::String(const String& reference) : ArrayList<char>(reference) {}

String::String() : ArrayList<char>() {
	this->clear();
}

String::~String(){}

size_t String::length() const {
	return this->len - 1;
}

void String::append(const String& str) {
	char** temp = new char*[this->length() + str.length() + 1];
	memcpy(temp, this->data, this->length() * sizeof(char*));

//	memcpy(temp + this->length(), str.data, str.length() * sizeof(char));
	for (int i = 0; i < str.length(); i++) {
		*(temp[i + this->length()]) = *(str.data[i]);
	}
	this->len += str.length();
	if (this->data) {
		delete[] this->data;
	}
	this->data = temp;
	*(this->data[this->len-1]) = '\0';
}

void String::append(const char* str) {
	String input(str);
	this->append(input);
}

const char* String::c_str() const {
	char* cstr = new char[this->len];
	for (int i = 0; i < this->len; i++) {
		cstr[i] = *(this->data[i]);
	}
	return cstr;
}

void String::clear() {
	ArrayList<char>::clear();
	this->data = new char*;
	this->data[0] = new char;
	*(this->data[0]) = '\0';
	this->len = 1;
}

void String::operator+=(const String& str) {
	this->append(str);
}

void String::operator+=(const char* str) {
	this->append(str);
}

void String::operator=(const String& str) {
	ArrayList::clear();
	this->len = str.len;
	this->data = new char*[len];
	for (int i = 0; i < this->len; i++) {
		this->data[i] = new char;
		*(this->data[i]) = *(str.data[i]);
	}
	//memcpy(this->data, str.data, this->len*sizeof(char));
}

void String::operator=(const char* str) {
/*
	if (this->data) {
		delete[] this->data;
	}
	this->len = strlen(str) + 1;
	this->data = new char[len];
	memcpy(this->data, str, len*sizeof(char));
*/
	this->operator=(String(str));
}

bool String::operator==(const String& str) {
	return !strcmp(this->c_str(), str.c_str());
}

ostream& operator<<(ostream& stream, const String& str) {
	stream << str.c_str();
	return stream;
}

String operator+(const String& left, const String& right) {
	String temp;
	temp.append(left);
	temp.append(right);
	return temp;
}

String operator+(const String& left, const char* right) {
	String temp;
	temp.append(left);
	temp.append(right);
	return temp;
}
