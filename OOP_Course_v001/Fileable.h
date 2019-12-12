#pragma once
#include "Loadable.h"
#include "Saveable.h"

class Fileable : public Loadable, public Saveable {
public:
	Fileable() {}
	~Fileable() {}
};

