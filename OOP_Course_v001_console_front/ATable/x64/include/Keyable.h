#pragma once
/* Copyright 2019 Andrieiev Danil */
#include <string>

namespace ATable {
	using namespace std;

	class Keyable {
	protected:
		string key;
	public:
		Keyable(string key);
		~Keyable();
		string getKey(); // returns key key
	};
}
