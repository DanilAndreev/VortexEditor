#pragma once
#include "Object.h"
#include <string>

namespace ATable {
	class Exception : public Object {
	protected:
		string message;
	public:
		Exception(string message) {
			this->message = message;
		}
		~Exception() {}
		string getMessage() {
			return this->message;
		}
	};


	class WrongIDException : public Exception {
	public:
		WrongIDException() : Exception("Exception: Wrong id exception") {}
	};

	class WrongColumnTypeException : public Exception {
	public:
		WrongColumnTypeException() : Exception("Exception: Wrong column type exception") {}
	};
}
