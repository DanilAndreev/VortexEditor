#pragma once
/* Copyright 2019 Andrieiev Danil */
#include <exception>

namespace WMenu {
	class WonderMenuException : public std::exception {
	public:
		const char* what() const override { return "Error: WonderMenuException"; }
	};

	class NoObjectFoundException : public WonderMenuException {
	public:
		const char* what() const override { return "Error: NoObjectFoundException"; }
	};

	class ZeroPointerException : public WonderMenuException {
	public:
		const char* what() const override { return "Error: ZeroPointerException"; }
	};
}
