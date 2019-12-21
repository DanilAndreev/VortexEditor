#include "DailyReport.h"

DailyReport::DailyReport() {
	this->extraditions.addObjectCreator((hash_code)typeid(Operation).hash_code(), []() -> Fileable * { return new Operation(); });
	this->returns.addObjectCreator((hash_code)typeid(Operation).hash_code(), []() -> Fileable * { return new Operation(); });
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

size_t DailyReport::getReturnsSize() {
	return this->returns.size();
}

void DailyReport::addExtradition(Operation* extradition) {
	if (extradition->isReturn()) {
		throw InputIsNotExtradition();
	}
	this->extraditions.push_back(extradition);
}

Operation* DailyReport::getExtradition(const size_t index) const {
	Operation* temp = dynamic_cast<Operation*>(this->extraditions.get(index));
	if (!temp) {
		throw ZeroPointerException();
	}
	return temp;
}

size_t DailyReport::getExtraditionsSize() {
	return this->extraditions.size();
}

void DailyReport::save(ofstream& stream) const {
	hash_code hash = (hash_code)typeid(DailyReport).hash_code();
	stream.write((char*)& hash, sizeof(hash_code));
	this->extraditions.save(stream);
	this->returns.save(stream);
}

void DailyReport::load(ifstream& stream) {
	hash_code hash = 0;
	stream.read((char*)& hash, sizeof(hash_code));
	if (hash != (hash_code)typeid(DailyReport).hash_code()) {
		throw WrongInputFileException();
	}
	this->extraditions.load(stream);
	this->returns.load(stream);
}

MagicJSON::JsonObject DailyReport::serialize() {
	MagicJSON::JsonObject json;
	MagicJSON::JsonArray jreturns;
	MagicJSON::JsonArray jextraditions;
	for (Fileable* item : this->returns) {
		Serializeable* serializeable = nullptr;
		if ((serializeable = dynamic_cast<Serializeable*>(item)) != nullptr) {
			jreturns.addObject(serializeable->serialize());
		}		
	}
	for (Fileable* item : this->extraditions) {
		Serializeable* serializeable = nullptr;
		if ((serializeable = dynamic_cast<Serializeable*>(item)) != nullptr) {
			jextraditions.addObject(serializeable->serialize());
		}
	}
	json.addString(L"__type", L"dailyreport");
	json.addInteger(L"__hash", typeid(DailyReport).hash_code());
	json.addArray(L"returns", jreturns);
	json.addArray(L"extraditions", jextraditions);
	return json;
}

void DailyReport::deserialize(MagicJSON::JsonObject json) {
	try {
		this->returns.clear();
		this->extraditions.clear();
		wstring type = json.getString(L"__type");
		if (type.compare(wstring(L"dailyreport"))) {
			throw UnexpectedTypeException();
		}
		MagicJSON::JsonArray jreturns = json.getArray(L"returns");
		MagicJSON::JsonArray jextraditions = json.getArray(L"extraditions");
		for (size_t i = 0; i < jreturns.size(); i++) {
			MagicJSON::JsonObject object = jreturns.getObject(i);
			long hash = object.getInteger(L"__hash");
			size_t s_hash = (size_t)hash;
			Fileable* item = this->returns.getObjectCreator(s_hash)();
			Serializeable* serializeable = nullptr;
			if ((serializeable = dynamic_cast<Serializeable*>(item)) == nullptr) {
				throw IncorrectObjectDataException();
			}
			serializeable->deserialize(object);
			this->returns.push_back(item);
		}
		for (size_t i = 0; i < jextraditions.size(); i++) {
			MagicJSON::JsonObject object = jextraditions.getObject(i);
			Fileable* item = this->returns.getObjectCreator(object.getInteger(L"__hash"))();
			Serializeable* serializeable = nullptr;
			if ((serializeable = dynamic_cast<Serializeable*>(item)) == nullptr) {
				throw IncorrectObjectDataException();
			}
			serializeable->deserialize(object);
			this->extraditions.push_back(item);
		}
	}
	catch (MagicJSON::NoObjectFoundException e) {
		throw IncorrectObjectDataException();
	}
}

Operation DailyReport::find(const wstring name) const {
	for (Fileable* item : this->returns) {
		Operation* operation = dynamic_cast<Operation*>(item);
		if (operation) {
			if (operation->getAbonent().getName() == name) {
				return *operation;
			}
		}
	}
	throw NoObjectFoundException();
}


Operation DailyReport::find(const short year) const {
	for (Fileable* item : this->returns) {
		Operation* operation = dynamic_cast<Operation*>(item);
		if (operation) {
			if (operation->getAbonent().getYear() == year) {
				return *operation;
			}
		}
	}
	throw NoObjectFoundException();
}


void DailyReport::operator=(const DailyReport& reference) {
	this->returns = reference.returns;
	this->extraditions = reference.extraditions;
}
