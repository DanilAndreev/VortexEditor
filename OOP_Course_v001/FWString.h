#pragma once
#include "Fileable.h"
#include "Exception.h"
#include <windows.h>

class FWString : public wstring, public Fileable {
public:
	FWString() : wstring(), Fileable() {}
	FWString(const LPCWSTR str) : wstring(str), Fileable() {}
	FWString(const FWString& reference) : wstring(reference), Fileable(reference) {}
	FWString(const wstring& reference) : wstring(reference) {}
	~FWString() {}
	virtual void save(ofstream& stream) const override;
	virtual void load(ifstream& stream) override;
public:
	using wstring::operator+=;
	using wstring::operator[];
	using wstring::operator=;
};

