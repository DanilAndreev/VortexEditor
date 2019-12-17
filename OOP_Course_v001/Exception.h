#pragma once
#include <string>
#include "Object.h"

using namespace std;

class Exception : public Object {
public:
	Exception() {}
	virtual ~Exception() {}
	virtual string getMessage() { return ""; }
};

class WrongInputFileException : public Exception {
public:
	virtual string getMessage() override {
		return string("Error: WrongInputFileException");
	}
};

class UnknownDataTypeException : public Exception {
public:
	virtual string getMessage() override {
		return string("Error: UnknownDataTypeException");
	}
};

class IndexOutOfBoundsException : public Exception {
public:
	virtual string getMessage() override {
		return string("Error: IndexOutOfBoundsException");
	}
};

class WrongInputDataException : public Exception {
public:
	virtual string getMessage() override {
		return string("Error: WrongInputDataException");
	}
};

class WrongInputValuesException : public WrongInputDataException {
public:
	virtual string getMessage() override {
		return string("Error: WrongInputValuesExxception");
	}
};

class SearchException : public Exception {
public:
	virtual string getMessage() override {
		return string("Error: SearchException");
	}
};

class NoObjectFoundException : public SearchException {
public:
	virtual string getMessage() override {
		return string("Error: NoObjectFoundException");
	}
};

class IncorrectRangeException : public SearchException {
public:
	virtual string getMessage() override {
		return string("Error: IncorrectRangeException");
	}
};

class ZeroPointerException : public Exception {
public:
	virtual string getMessage() override {
		return string("Error: ZeroPtrException");
	}
};
