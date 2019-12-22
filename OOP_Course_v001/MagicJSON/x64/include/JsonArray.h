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
#include "JsonItem.h"
#include "JsonObject.h"
#include <vector>
#include <string>
#include "JsonTokenizer.h"
#include "JsonExceptions.h"


namespace MagicJSON {
	class JsonArray : protected vector<JsonItem*>, public JsonItem {
	public:
		JsonArray() {}  // constructor by default
		JsonArray(wstring data);  // construct json array from string
		JsonArray(const JsonArray& reference);  // copy constructor
		~JsonArray();
	public:
		virtual JsonArray getArray(size_t index);  // returns json array from index position or throws IndexOutOfRangeException or IncorrectRequestException
		virtual double getFloat(size_t index);  // returns floating point number from index position or throws IndexOutOfRangeException or IncorrectRequestException
		virtual long getInteger(size_t index);  // returns integer number from index position or throws IndexOutOfRangeException or IncorrectRequestException
		virtual wstring getString(size_t index);  // returns string from index position or throws IndexOutOfRangeException or IncorrectRequestException
		virtual JsonObject getObject(size_t index);  // returns json object from index position or throws IndexOutOfRangeException or IncorrectRequestException
		virtual void addArray(JsonArray value);  // adds json array to array
		virtual void addFloat(double value);  // adds floating point number to array
		virtual void addInteger(long value);  // adds integer number array to array
		virtual void addString(wstring value);  // adds string to array
		virtual void addObject(JsonObject value);  // adds json object to array
	public:
		virtual wstring toString() override;  // returns json array converted to string
		virtual JsonItem* copy() override;
		void remove(size_t index);  // removes item on index position from json array or throws IndexOutOfRangeException
	public:
		using vector<JsonItem*>::clear;
		using vector<JsonItem*>::capacity;
		using vector<JsonItem*>::empty;
		using vector<JsonItem*>::size;
	protected:
		void parse(wstring json);
	public:
		using vector<JsonItem*>::operator=;
	};
}

