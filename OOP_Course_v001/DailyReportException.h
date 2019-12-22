#pragma once
#include "Exception.h"

class InputIsNotReturn : public WrongInputDataException {
public:
	char const* what() const noexcept override { return "Error: InputIsNotReturn"; }
};

class InputIsNotExtradition : public WrongInputDataException {
public:
	char const* what() const noexcept override { return "Error: InputIsNotExtradition"; }
};
