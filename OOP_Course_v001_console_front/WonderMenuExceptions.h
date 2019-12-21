#pragma once
#include <exception>

class WonderMenuException : public std::exception {
public:
	const char* what() const override { return "Error: WonderMenuException"; }
};

class NoObjectFoundException : public WonderMenuException {
public:
	const char* what() const override { return "Error: NoObjectFoundException"; }
};

