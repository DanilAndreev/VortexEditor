#pragma once
#include <exception>

using namespace std;

class PipeException : public exception {
	const char* what() const override { return "Error: PipeException"; }
};

class PipeException : public PipeException {
	const char* what() const override { return "Error: PipeException"; }
};


