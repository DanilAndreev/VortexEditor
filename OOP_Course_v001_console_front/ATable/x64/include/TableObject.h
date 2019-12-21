#pragma once
/* Copyright 2019 Andrieiev Danil */
#include <windows.h>


namespace ATable {
	using namespace std;

	class TableObject {
	public:
		TableObject();
		virtual ~TableObject();
		virtual TableObject* clone();
	};
}
