#pragma once
#include "MagicJSON.h"
#include "SerializeExceptions.h"

class Serializeable {
public:
	virtual MagicJSON::JsonObject serialize() = 0;
	virtual void deserialize(MagicJSON::JsonObject json) = 0;
};
