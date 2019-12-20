#pragma once
#include "Object.h"
#include <string>

namespace MagicJSON {
	class JsonItem : public Object {
	public:
		JsonItem() {}
		~JsonItem() {}
		virtual wstring toString() = 0;
	public:
		virtual JsonItem* copy() = 0;
	};
}
