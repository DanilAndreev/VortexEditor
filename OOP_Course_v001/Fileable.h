#pragma once
#include "Loadable.h"
#include "Saveable.h"

typedef long hash_code;

class Fileable : public Loadable, public Saveable {
public:
	Fileable() {}
	~Fileable() {}
};

