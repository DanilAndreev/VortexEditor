#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "TableObject.h"
#include <string>
#include <iostream>

namespace ATable {
	class Cell : public TableObject {
	private:
		unsigned int width;
	public:
		Cell();
		~Cell();
		Cell(Cell* input);
		virtual string output() = 0; // virtual function, which should return string, which well display in table cell
		void print(ostream& stream); // prints sata to stream (for debug)
		void setWidth(unsigned int width); // sets the width of cell
		unsigned int getWidth(); // returns the width of cell
	private:
		string boundary(string value); // crops the text by cell width
	};
}

