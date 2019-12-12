#include "DailyReport.h"

DailyReport::DailyReport(const DailyReport& reference) : Object(reference) {
	this->returns = reference.returns;
	this->extraditions = reference.extraditions;
}

void DailyReport::addReturn(Fileable* return_) {
	this->returns.add(return_);
}

Fileable* DailyReport::getReturn(const size_t index) const {
	return this->returns.get(index);
}

void DailyReport::addExtradition(Fileable* extradition) {
	this->extraditions.add(extradition);
}

Fileable* DailyReport::getExtradiotion(const size_t index) const {
	return this->extraditions.get(index);
}

