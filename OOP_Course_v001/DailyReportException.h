#pragma once
#include "Exception.h"

class InputIsNotReturn : public WrongInputDataException {
public:
	char const* what() const override { return "Error: InputIsNotReturn"; }
};

class InputIsNotExtradition : public WrongInputDataException {
public:
	char const* what() const override { return "Error: InputIsNotExtradition"; }
};
