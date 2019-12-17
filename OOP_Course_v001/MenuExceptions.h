#pragma once
#include "Object.h"

#include <string>

namespace Menu {
	class Exception : public Object {
	public:
		string message;
	public:
		Exception(string message) {
			this->message = message;
		}
		~Exception() {}
		string getMessage() { // returns message of exception
			return this->message;
		}
	};

	class IDOutOfRangeException : public Exception {
	public:
		IDOutOfRangeException() : Exception("Exception: Id out of range exception") {}
		~IDOutOfRangeException() {}
	};

	class KeyAlreadyExistException : public Exception {
	public:
		KeyAlreadyExistException() : Exception("Exception: Key already exist in this sequence") {}
		~KeyAlreadyExistException() {}
	};
}