#pragma once
#include <exception>

using namespace std;


class WrongInputFileException : public exception {
public:
	char const* what() const noexcept override { return "Error: WrongInputFileException"; }
};

class UnknownDataTypeException : public exception {
public:
	char const* what() const noexcept override { return "Error: UnknownDataTypeException"; }
};

class IndexOutOfBoundsException : public exception {
public:
	char const* what() const noexcept override { return "Error: IndexOutOfBoundsException"; }
};

class WrongInputDataException : public exception {
public:
	char const* what() const noexcept override { return "Error: WrongInputDataException"; }
};

class WrongInputValuesException : public WrongInputDataException {
public:
	char const* what() const noexcept override { return "Error: WrongInputValuesException"; }
};

class SearchException : public exception {
public:
	char const* what() const noexcept override { return "Error: SearchException"; }
};

class NoObjectFoundException : public SearchException {
public:
	char const* what() const noexcept override { return "Error: NoObjectFoundException"; }
};

class IncorrectRangeException : public SearchException {
public:
	char const* what() const noexcept override { return "Error: IncorrectRangeException"; }
};

class ZeroPointerException : public exception {
public:
	char const* what() const noexcept override { return "Error: ZeroPointerException"; }
};
