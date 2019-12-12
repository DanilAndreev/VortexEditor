#pragma once
#include "Object.h"
template <class T>
class List : public Object {
public:
	virtual void add(T object) = 0;
	virtual T get(size_t index) const = 0;
	virtual void clear() = 0;
	virtual size_t size() = 0;
};

