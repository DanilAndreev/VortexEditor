#pragma once
class Returnable {
protected:
	bool isreturn;
public:
	Returnable(const bool isreturn) : isreturn(isreturn) {}
	Returnable() : Returnable(false) {}
	~Returnable() {}
	Returnable(const Returnable& reference);
	bool isReturn() const { return this->isreturn; }
	void setType(const bool isreturn) { this->isreturn = isreturn; }
};

