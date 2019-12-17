#pragma once
#include "Object.h"
#include "FVector.h"
#include "Operation.h"
#include "DailyReportException.h"

class DailyReport : public Object, public Fileable {
protected:
	FVector returns;
	FVector extraditions;
public:
	DailyReport();
	~DailyReport() {}
	DailyReport(const DailyReport& reference);
	void addReturn(Operation* return_);
	Operation* getReturn(const size_t index) const;
	void addExtradition(Operation* extradition);
	Operation* getExtradiotion(const size_t index) const;
	virtual void save(ofstream& stream) const override;
	virtual void load(ifstream& stream) override;
public:
	void operator= (const DailyReport& reference);
};
