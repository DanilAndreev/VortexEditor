#pragma once
#include "JsonTokenizer.h"
#include "JsonString.h"
#include <iostream>
#include <set>
#include <utility>
#include <windows.h>

using namespace std;


namespace MagicJSON {
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
