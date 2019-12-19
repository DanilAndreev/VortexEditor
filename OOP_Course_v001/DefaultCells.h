#pragma once
#include "Cell.h"

namespace ATable {
	class StringCell : public Cell {
	public:
		string value;
	public:
		StringCell(string value) {
			this->value = value;
		}
		StringCell(StringCell* input) {
			this->value = input->value;
		}
		string output() {
			return this->value;
		}
		virtual Object* clone() {
			Cell* clone = new StringCell(this->value);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class IntegerCell : public Cell {
	public:
		int value;
	public:
		IntegerCell(int value) {
			this->value = value;
		}
		IntegerCell(IntegerCell* input) {
			this->value = input->value;
		}
		string output() {
			return to_string(this->value);
		}
		virtual Object* clone() {
			Cell* clone = new IntegerCell(this->value);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class LongCell : public Cell {
	public:
		int value;
	public:
		LongCell(int value) {
			this->value = value;
		}
		LongCell(LongCell* input) {
			this->value = input->value;
		}
		string output() {
			return to_string(this->value);
		}
		virtual Object* clone() {
			Cell* clone = new LongCell(this->value);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class FloatCell : public Cell {
	public:
		float value;
		int percision;
	public:
		FloatCell(float value, int percision) {
			this->value = value;
			this->percision = percision;
		}
		FloatCell(float value) : FloatCell(value, 3) {}
		FloatCell(FloatCell* input) {
			this->value = input->value;
			this->percision = input->percision;
		}
		string output() {
			string integer = to_string((int)value);
			string fractional = to_string((int)(abs(value - (int)value) * pow(10, percision)));
			string result;
			result += integer + "." + fractional;
			return result;
		}
		virtual Object* clone() {
			Cell* clone = new FloatCell(this->value, this->percision);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class DoubleCell : public Cell {
	public:
		float value;
		int percision;
	public:
		DoubleCell(double value, int percision) {
			this->value = value;
			this->percision = percision;
		}
		DoubleCell(double value) : DoubleCell(value, 3) {}
		DoubleCell(DoubleCell* input) {
			this->value = input->value;
			this->percision = input->percision;
		}
		string output() {
			string integer = to_string((int)value);
			string fractional = to_string((int)(abs(value - (int)value) * pow(10, percision)));
			string result;
			result += integer + "." + fractional;
			return result;
		}
		virtual Object* clone() {
			Cell* clone = new DoubleCell(this->value, this->percision);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

}
