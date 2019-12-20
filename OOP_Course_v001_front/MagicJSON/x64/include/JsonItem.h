#pragma once
#include <string>

namespace MagicJSON {
	class JsonItem {
	public:
		JsonItem() {}
		~JsonItem() {}
		virtual wstring toString() = 0;
	public:
		virtual JsonItem* copy() = 0;
	};
}
