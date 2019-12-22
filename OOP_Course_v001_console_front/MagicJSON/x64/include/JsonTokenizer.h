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
#include <string>
#include <utility>


namespace MagicJSON {
	using namespace std;

	typedef pair<size_t, wstring> Token;
	class JsonTokenizer {
	public:
		static const size_t EOF_TOKEN = 0;
		static const size_t STRING_TOKEN = 1;
		static const size_t INTEGER_TOKEN = 2;
		static const size_t FLOAT_TOKEN = 3;
		static const size_t ARRAY_TOKEN = 4;
		static const size_t OBJECT_TOKEN = 5;
		static const size_t NULL_TOKEN = 6;
		static const size_t DOUBLEDOTS_TOKEN = 7;
		static const size_t COMA_TOKEN = 8;
	protected:
		size_t position;
		wstring text;
	public:
		JsonTokenizer(wstring text) : text(text), position(0) {}
		~JsonTokenizer() {}
		Token next_token();
	protected:
		static bool is_skipable(wchar_t symbol);
	};
}
