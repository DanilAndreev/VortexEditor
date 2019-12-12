#pragma once
#include "ArrayList.h"
#include <iostream>

class String : private ArrayList<char> {
public:
	String(const char* str);
	String(const String& reference);
	String();
	~String();
	size_t length() const;
	void append(const String& str);
	void append(const char* str);
	const char* c_str() const;
	void clear();
public:
	friend ostream& operator << (ostream& stream, const String& str);
	friend String operator+(const String& left, const String& right);
	friend String operator+(const String& left, const char* right);
	void operator+=(const String& str);
	void operator+=(const char* str);
	void operator = (const String& str);
	void operator = (const char* str);
	bool operator == (const String& str);
};
