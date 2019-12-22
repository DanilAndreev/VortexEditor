#pragma once
/*
   JsonArray.cpp, JsonObject.cpp JsonString.cpp, JsonTokenizer.cpp
   JsonArray.h JsonExceptions.h JsonItem.h JsonObject.h JsonString.h JsonTokenizer.h MagicJSO.h
   Copyright (C) 2019 Andrieiev Danil
   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.
   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:
   1. The origin of this source code must not be misrepresented; you must not
	  claim that you wrote the original source code. If you use this source code
	  in a product, an acknowledgment in the product documentation would be
	  appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must not be
	  misrepresented as being the original source code.
   3. This notice may not be removed or altered from any source distribution.
   Andrieiev Danil danssg08@gmail.com
   version 1.0.4
*/
#include "JsonTokenizer.h"
#include "JsonString.h"
#include <iostream>
#include <set>
#include <utility>
#include <windows.h>


namespace MagicJSON {
	using namespace std;

	class JsonArray;
	
	typedef pair<wstring, JsonItem*> JItem;
	typedef set<JItem, bool(*)(JItem, JItem)> JSet;

	class JsonObject : protected JSet, public JsonItem {
	public:
		JsonObject() : JSet(&comparator) {}  // constructor by default
		JsonObject(wstring data);  // construct json hierarchy from string
		JsonObject(const JsonObject& reference);  // copy constructor
		~JsonObject();
	public:
		virtual void addString(wstring key, wstring value);  // adds string field to json
		virtual void addArray(wstring key, JsonArray value);  // adds json array field to json
		virtual void addInteger(wstring key, long value);  // adds integer number field to json
		virtual void addFloat(wstring key, double value);  // adds floating point number field to json
		virtual void addObject(wstring key, JsonObject value);  // adds another json object field to json
		virtual wstring getString(wstring key);  // returns string or throws NoObjectFoundException or IncorrectRequestException
		virtual JsonArray getArray(wstring key);  // returns json array or throws NoObjectFoundException or IncorrectRequestException
		virtual long getInteger(wstring key);  // returns integer number or throws NoObjectFoundException or IncorrectRequestException
		virtual double getFloat(wstring key);  // returns floating point number or throws NoObjectFoundException or IncorrectRequestException
		virtual JsonObject getObject(wstring key);  // returns json object or throws NoObjectFoundException or IncorrectRequestException
	public:
		virtual wstring toString() override;  // returns json hierarchy converted to string
		virtual JsonItem* copy() override;
		void remove(wstring key);  // removes field with selected key from json hierarchy or throws NoObjectFoundException
	public:
		using JSet::clear;
	protected:
		virtual void parse(wstring json);
		static bool comparator(JItem less, JItem higher);
	public:
		using JSet::operator=;
	};
}
