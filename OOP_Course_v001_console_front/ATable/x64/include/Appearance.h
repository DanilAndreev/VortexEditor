#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "TableObject.h"
#include <iostream>

namespace ATable {
	class Appearance : public TableObject {
	public:
		char left_top_corner;
		char right_top_corner;
		char left_bottom_corner;
		char right_bottom_corner;

		char vertical_line;
		char horizontal_line;

		char left_separator;
		char right_separator;
		char top_separator;
		char bottom_separator;

		char center_separator;
	public:
		Appearance();
		~Appearance();
		void print(ostream & stream); // prints the appearance to stream stream
		friend ostream& operator<< (ostream& stream, Appearance obj);
		friend ostream& operator<< (ostream& stream, Appearance* obj);
	};
}

