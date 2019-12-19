#pragma once
#include "Object.h"
#include "SimpleColumn.h"
#include "TableExceptions.h"
#include "Appearance.h"

#include <vector>
#include <iostream>
#include <cmath>

namespace ATable {
	class Table : public Object {
	public:
		vector<Column*>* columns;
		Appearance preset;
		string name;
	public:
		Table(Appearance preset, string name);
		~Table();
		void addColumn(Column* column);
		void addCell(int column, Cell* cell);
		virtual void print(ostream& stream);
	private:
		Column* getColumn(int id);
		void drawLine(ostream & stream, char left_corner, char horizontal_line, char center_separator, char right_corner);
		void drawRow(ostream & stream, unsigned int row, char vertical_line);
		void drawColumnsHeaders(ostream& stream, char vertical_line);
		unsigned int getMaxRowHeight();
	public:
		static string boundary(string value, int width);
	};
}

