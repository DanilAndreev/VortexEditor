#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "DefaultCells.h"
#include "NamedColumn.h"

namespace ATable {
	class IdColumn : public NamedColumn {
	public:
		IdColumn(unsigned int width, string name, string key);
		IdColumn(unsigned int width, string key) : IdColumn(width, "ID", key) {}
		IdColumn(string key) : IdColumn(3, "ID", key) {}
		~IdColumn();
		Cell* getCellClone(int id);  // returns new cell with id value inside
	private:
		Cell* getCell(int id); // returns nullptr (not used)
	};

}

