#pragma once
#include "DailyReport.h"
#include <string>


namespace StatTools {
	template <class T>
	double statistic(DailyReport* target) {
		double total = 0;
		size_t number = 0;
		for (size_t i = 0; i < target->getReturnsSize(); i++) {
			if (typeid(T) == typeid(int)) {
				total += target->getReturn(i)->getDisk().getLength();
				number++;
			}
			if (typeid(T) == typeid(std::wstring)) {
				total += target->getReturn(i)->getDisk().getName().length();
				number++;
			}
		}
		for (size_t i = 0; i < target->getExtraditionsSize(); i++) {
			if (typeid(T) == typeid(int)) {
				total += target->getExtradition(i)->getDisk().getLength();
				number++;
			}
			if (typeid(T) == typeid(std::wstring)) {
				total += target->getExtradition(i)->getDisk().getName().length();
				number++;
			}
		}
		if (!number) {
			return 0;
		}
		return total / number;
	}
}
