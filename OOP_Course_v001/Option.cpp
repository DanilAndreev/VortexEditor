#include "Option.h"


namespace Menu {
	Option::Option(string text, string key, void(*callback)(Object* obj), Object* obj) {
		this->text = text;
		this->key = key;
		this->callback = callback;
		this->object = obj;
	}

	Option::~Option() {}

	void Option::selected() {
		this->callback(object);
	}
	string Option::getKey() {
		return this->key;
	}
	string Option::getText() {
		return this->text;
	}
}


