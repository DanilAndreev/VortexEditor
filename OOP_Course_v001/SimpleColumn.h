#pragma once
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
		SimpleColumn(string name, unsigned int width);
		~SimpleColumn();
		void addCell(Cell* cell);
		Cell* getCell(int id);
		Cell* getCellClone(int id);
		unsigned int getHeight();
	};
}

