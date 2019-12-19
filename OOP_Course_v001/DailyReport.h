#pragma once
#include "Object.h"
#include "FVector.h"
#include "Operation.h"
#include "DailyReportException.h"

class DailyReport : public Object, public Fileable, public Serializeable{
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
public:
	void save(ofstream& stream) const override;
	void load(ifstream& stream) override;
	MagicJSON::JsonObject serialize() override;
	void deserialize(MagicJSON::JsonObject json) override;
public:
	Operation find(const wstring name) const;
	Operation find(const short year) const;
public:
	void operator= (const DailyReport& reference);
};
