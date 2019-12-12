#pragma once
#include "Object.h"
#include "FileableArray.h"


class DailyReport : public Object {
protected:
	FileableArray returns;
	FileableArray extraditions;
public:
	DailyReport() {}
	~DailyReport() {}
	DailyReport(const DailyReport& reference);
	void addReturn(Fileable* return_);
	Fileable* getReturn(const size_t index) const;
	void addExtradition(Fileable* extradition);
	Fileable* getExtradiotion(const size_t index) const;
};

