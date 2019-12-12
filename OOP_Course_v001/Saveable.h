#pragma once

#include <fstream>
using namespace std;

class Saveable {
public:
	Saveable() {}
	~Saveable() {}
	virtual void save(ofstream& stream) const {}
};