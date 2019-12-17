#include "DailyReport.h"

DailyReport::DailyReport() {
	this->extraditions.addObjectCreator(typeid(Operation).hash_code(), []() -> Fileable * { return new Operation(); });
	this->returns.addObjectCreator(typeid(Operation).hash_code(), []() -> Fileable * { return new Operation(); });
}

DailyReport::DailyReport(const DailyReport& reference) : Object(reference) {
	this->returns = reference.returns;
	this->extraditions = reference.extraditions;
}

void DailyReport::addReturn(Operation* return_) {
	if (!return_->isReturn()) {
		throw InputIsNotReturn();
	}
	this->returns.push_back(return_);
}

Operation* DailyReport::getReturn(const size_t index) const {
	Operation* temp = dynamic_cast<Operation*>(this->returns.get(index));
	if (!temp) {
		throw ZeroPointerException();
	}
	return temp;
}

void DailyReport::addExtradition(Operation* extradition) {
	if (extradition->isReturn()) {
		throw InputIsNotExtradition();
	}
	this->extraditions.push_back(extradition);
}

Operation* DailyReport::getExtradiotion(const size_t index) const {
	Operation* temp = dynamic_cast<Operation*>(this->extraditions.get(index));
	if (!temp) {
		throw ZeroPointerException();
	}
	return temp;
}

void DailyReport::save(ofstream& stream) const {
	size_t hash = typeid(DailyReport).hash_code();
	stream.write((char*)& hash, sizeof(size_t));
	this->extraditions.save(stream);
	this->returns.save(stream);
}

void DailyReport::load(ifstream& stream) {
	size_t hash = 0;
	stream.read((char*)& hash, sizeof(size_t));
	if (hash != typeid(DailyReport).hash_code()) {
		throw WrongInputFileException();
	}
	this->extraditions.load(stream);
	this->returns.load(stream);
}

void DailyReport::operator=(const DailyReport& reference) {
	this->returns = reference.returns;
	this->extraditions = reference.extraditions;
}
