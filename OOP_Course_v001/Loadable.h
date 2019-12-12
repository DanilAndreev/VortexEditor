#pragma once

#include <fstream>

using namespace std;

class Loadable {
public:
	Loadable() {}
	~Loadable() {}
	virtual void load(ifstream& stream) {}
};
