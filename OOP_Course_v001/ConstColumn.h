#pragma once
#include "Column.h"
#include "DefaultCells.h"

namespace ATable {
	class ConstColumn : public Column {
	protected:
		Cell* cell;
	public:
		ConstColumn(string value);
		~ConstColumn();
		Cell* getCell(int id);
		Cell* getCellClone(int id);
	};
}

