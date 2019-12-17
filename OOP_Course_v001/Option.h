#pragma once
#include "Object.h"

#include <string>

namespace Menu {
	class Option : public Object {
		void(*callback)(Object* obj);
		string text;
		string key;
		Object* object;
	public:
		Option(string text, string key, void(*callback)(Object* obj), Object* obj);
		~Option();
		void selected(); // calling callback function;
		string getKey(); // returns key
		string getText(); // returns text
	};
}
