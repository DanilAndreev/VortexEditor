#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "Column.h"
#include "DefaultCells.h"

namespace ATable {
	class ConstColumn : public Column {
	protected:
		Cell* cell;
	public:
		ConstColumn(string value, string key);
		~ConstColumn();
		Cell* getCell(int id); // returns cell cell (id not used)
		Cell* getCellClone(int id); // // returns clone of cell cell (id not used)
	};
}

