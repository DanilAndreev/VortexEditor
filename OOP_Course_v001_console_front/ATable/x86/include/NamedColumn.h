#pragma once
/* Copyright 2019 Andrieiev Danil */
#include "Column.h"
#include "Namable.h"

namespace ATable {
	class NamedColumn : public Column, public Namable {
	public:
		NamedColumn(unsigned int width, string name, string key);
		~NamedColumn();
	};
}

