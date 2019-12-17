#pragma once
#include "Exception.h"

class InputIsNotReturn : public WrongInputDataException {
public:
	virtual string getMessage() override {
		return string("Error: InputIsNotReturn");
	}
};

class InputIsNotExtradition : public WrongInputDataException {
public:
	virtual string getMessage() override {
		return string("Error: InputIsNotExtradition");
	}
};
