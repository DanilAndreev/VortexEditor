#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "TableObject.h"
#include "Cell.h"
#include "TableExceptions.h"
#include "Keyable.h"

namespace ATable {
	class Column : public TableObject, public Keyable{
	public:
		unsigned int width;
	public:
		Column(unsigned int width, string key);
		~Column();
		unsigned int getWidth(); // returns width of column
		void setWidth(unsigned int width); // sets the width of column
		virtual Cell* getCell(int id) = 0; // virtual function, which should return cell on position id
		virtual Cell* getCellClone(int id) = 0; // virtual function, which should return clone of cell on position id
	};
}

