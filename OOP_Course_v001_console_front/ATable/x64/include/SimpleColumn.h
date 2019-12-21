#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "Cell.h"
#include "NamedColumn.h"
#include <vector>

namespace ATable {
	class SimpleColumn : public NamedColumn{
	public:
		string name;
	protected:
		vector<Cell*>* cells;
	public:
		SimpleColumn(string name, unsigned int width, string key);
		~SimpleColumn();
		void addCell(Cell* cell); // adds cell cell to column
		Cell* getCell(int id); // returns cell on position id
		Cell* getCellClone(int id); // returns new instance of cell on position id
		unsigned int getHeight(); // returns height of column (number of cells inside)
	};
}

