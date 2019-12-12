#pragma once
#include "Fileable.h"
#include "SortableArrayList.h"
#include "String.h"
#include "Exception.h"
#include <string>

class FileableArray : public SortableArrayList<Fileable*>, public Fileable {
protected:
	ArrayList<Fileable*(*)(size_t hash)> types;
public:
	FileableArray() : SortableArrayList() {}
	~FileableArray();
	virtual void save(ofstream& stream) const;
	virtual void load(ifstream& stream);
	void addLoadableType(Fileable*(*callback)(size_t hash));
	//Loadable(*)(String& name) getLoadableType(size_t index);
};
