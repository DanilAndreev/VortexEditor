#pragma once
#include "Column.h"
#include "Namable.h"

namespace ATable {
	class NamedColumn : public Column, public Namable {
	public:
		NamedColumn(unsigned int width, string name);
		~NamedColumn();
	};
}

