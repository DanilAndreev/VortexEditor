#pragma once
#include "Fileable.h"
#include "HashSet.h"
#include "Object.h"
#include "Exception.h"
#include <vector>

class FVector : public vector<Fileable*>, public Fileable, public Object{
	HashSet<Fileable* (*)(void)> creators;
public:
	FVector(): vector<Fileable*>(), Fileable(), Object() {}
	FVector(const FVector& reference) : vector<Fileable*>(reference), Fileable(reference), Object(reference) {}
	~FVector() {}
	virtual Fileable* get(size_t index) const;
	virtual void save(ofstream& stream) const;
	virtual void load(ifstream& stream);
	void addObjectCreator(size_t hash, Fileable* (*creator)(void));
};
