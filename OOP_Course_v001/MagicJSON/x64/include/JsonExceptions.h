#pragma once

using namespace std;

namespace MagicJSON {
	class JsonException : public exception {
	public:
		virtual char const* what() const { return "Error: JsonException"; }
	};

	class IncorrectRequestException : public JsonException {
	public:
		virtual char const* what() const override { return "Error: IncorrectRequestException"; }
	};

	class IndexOutOfRangeException : public JsonException {
	public:
		virtual char const* what() const override { return "Error: IndexOutOfRangeException"; }
	};

	class ReadingException : public JsonException {
	public:
		virtual char const* what() const override { return "Error: ReadingException"; }
	};

	class NoObjectFoundException : public JsonException {
	public:
		virtual char const* what() const override { return "Error: NoObjectFoundException"; }
	};

	class ErrorReadingFileException : public ReadingException {
	public:
		virtual char const* what() const override { return "Error: ErrorReadingFileException"; }
	};

	class ErrorReadingTextException : public ReadingException {
	public:
		virtual char const* what() const override { return "Error: ErrorReadingTextException"; }
	};

	class UnexpectedFileEndException : public ErrorReadingFileException {
	public:
		virtual char const* what() const override { return "Error: UnexpectedFileEndException"; }
	};

	class UnexpectedTextEndException : public ErrorReadingTextException {
	public:
		virtual char const* what() const override { return "Error: UnexpectedTextEndException"; }
	};

}
