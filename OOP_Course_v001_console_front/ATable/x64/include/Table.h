#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "TableObject.h"
#include "SimpleColumn.h"
#include "TableExceptions.h"
#include "Appearance.h"
#include <vector>
#include <iostream>
#include <cmath>

namespace ATable {
	class Table : public TableObject {
	public:
		vector<Column*>* columns;
		Appearance preset;
		string name;
	public:
		Table(Appearance preset, string name);
		~Table();
		void addColumn(Column* column); // adds column column to table
		void addCell(int column_id, Cell* cell); // adds cell cell to column with id column
		void addCell(string column_key, Cell* cell); // adds cell cell to column with key column_key
		virtual void print(ostream& stream); // prints table to stream stream
	private:
		Column* getColumn(int id); // returns column on position id
		Column* getColumn(string key); // returns column with key key
		int getColumnId(string key); // returns id of column with key key
		void drawLine(ostream & stream, char left_corner, char horizontal_line, char center_separator, char right_corner); // draws line to stream
		void drawRow(ostream & stream, unsigned int row, char vertical_line); // draws row of values to stream
		void drawColumnsHeaders(ostream& stream, char vertical_line); // draws columns headers to stream
		unsigned int getMaxRowHeight(); // returns height of the highest column in table
	public:
		static string boundary(string value, int width); // crops value by width width and returns cropped string
	public:
		friend ostream& operator<<(ostream& stream, Table& table);
	};
}

