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
#include <exception>

namespace MagicJSON {
	using namespace std;
	class JsonException : public exception {
	public:
		char const* what() const noexcept override{ return "Error: JsonException"; }
	};

	class IncorrectRequestException : public JsonException {
	public:
		virtual char const* what() const noexcept override { return "Error: IncorrectRequestException"; }
	};

	class IndexOutOfRangeException : public JsonException {
	public:
		virtual char const* what() const noexcept override { return "Error: IndexOutOfRangeException"; }
	};

	class ReadingException : public JsonException {
	public:
		virtual char const* what() const noexcept override { return "Error: ReadingException"; }
	};

	class NoObjectFoundException : public JsonException {
	public:
		virtual char const* what() const noexcept override { return "Error: NoObjectFoundException"; }
	};

	class ErrorReadingFileException : public ReadingException {
	public:
		virtual char const* what() const noexcept override { return "Error: ErrorReadingFileException"; }
	};

	class ErrorReadingTextException : public ReadingException {
	public:
		virtual char const* what() const noexcept override { return "Error: ErrorReadingTextException"; }
	};

	class UnexpectedFileEndException : public ErrorReadingFileException {
	public:
		virtual char const* what() const noexcept override { return "Error: UnexpectedFileEndException"; }
	};

	class UnexpectedTextEndException : public ErrorReadingTextException {
	public:
		virtual char const* what() const noexcept override { return "Error: UnexpectedTextEndException"; }
	};

}
