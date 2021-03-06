#pragma once
#include <exception>

using namespace std;

class SerializeException : public exception {
public:
	const char* what() const noexcept override { return "Error: SerializeException"; }
};

class IncorrectObjectDataException : public SerializeException {
public:
	const char* what() const noexcept override { return "Error: IncorrectObjectDataException"; }
};

class UnexpectedTypeException : public SerializeException {
public:
	const char* what() const noexcept override { return "Error: UnexpectedTypeException"; }
};
