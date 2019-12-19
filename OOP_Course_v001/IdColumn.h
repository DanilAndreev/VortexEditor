#pragma once
#include "DefaultCells.h"
#include "NamedColumn.h"

namespace ATable {
	class IdColumn : public NamedColumn {
	public:
		IdColumn(unsigned int width, string name);
		IdColumn(unsigned int width) : IdColumn(width, "ID") {}
		IdColumn() : IdColumn(3, "ID") {}
		~IdColumn();
		Cell* getCell(int id);
		Cell* getCellClone(int id);
	};

}

