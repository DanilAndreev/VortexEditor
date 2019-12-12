#pragma once
#include "Object.h"
#include "String.h"
#include "Fileable.h"
#include "Exception.h"

class BaseClass : public Object, public Fileable {
public:
	int integer;
	float flt;
public:
	BaseClass();
	BaseClass(int integer, float flt);
	~BaseClass();
	virtual void save(ofstream& stream) const;
	virtual void load(ifstream& stream);
};

