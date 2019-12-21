#pragma once
/* Copyright 2019 Andrieiev Danil */
#include <exception>

namespace ATable {
	class ATableException : public exception {
	public:
		const char* what() const override { return "Error ATableException"; }
	};

	class WrongIDException : public ATableException {
	public:
		const char* what() const override { return "Error WrongIDException"; }
	};

	class KeyNotExistException : public ATableException {
	public:
		const char* what() const override { return "Error KeyNotExistException"; }
	};

	class WrongColumnTypeException : public ATableException {
	public:
		const char* what() const override { return "Error WrongColumnTypeException"; }
	};
}
