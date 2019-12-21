#pragma once
/* Copyright 2019 Andrieiev Danil */
#include <string>

namespace ATable {
	using namespace std;

	class Namable {
	public:
		string name;
	public:
		Namable(string name);
		~Namable();
		string getName(); // returns name name
		void setName(string name); // sets name
	};
}

