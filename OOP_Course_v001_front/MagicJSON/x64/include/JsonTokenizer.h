#pragma once
#include <string>
#include <utility>

using namespace std;

namespace MagicJSON {
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
