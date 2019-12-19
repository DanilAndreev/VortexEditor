#pragma once
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

