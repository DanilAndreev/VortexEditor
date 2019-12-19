#pragma once
#include "Object.h"
#include "Cell.h"
#include "TableExceptions.h"

namespace ATable {
	class Column : public Object {
	public:
		unsigned int width;
	public:
		Column(unsigned int width);
		~Column();
		unsigned int getWidth();
		void setWidth(unsigned int width);
		virtual Cell* getCell(int id) = 0;
		virtual Cell* getCellClone(int id) = 0;
	};
}

