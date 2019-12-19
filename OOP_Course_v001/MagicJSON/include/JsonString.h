#pragma once
#include "JsonItem.h"
#include "windows.h"
#include <string>

using namespace std;

namespace MagicJSON {
	class JsonString : public wstring, public JsonItem {
	public:
		JsonString() : std::wstring() {}
		JsonString(LPCWSTR str) : wstring(str) {}
		JsonString(wstring str) : wstring(str) {}
		JsonString(const JsonString& reference) : wstring(reference), JsonItem(reference) {}
		~JsonString() {}
	public:
		virtual wstring toString() override;
		virtual JsonItem* copy() override;
	public:
		using wstring::operator=;
	};
}
