#pragma once
#include "ArrayList.h"

template <class T>
class Set : public ArrayList<T> {
protected:
	bool (*comparator)(T, T);
public:
	Set(bool (*comparator)(T, T));
	Set();
	~Set() {}
	Set(const Set& reference) : ArrayList(reference) {}
	virtual T search(bool (*identificator)(T));
	virtual void add(const T object);
protected:
	size_t searchPosition(T object);
	size_t searchPosition(T& object, size_t begin, size_t end);
	static bool defaultComparator(T less, T higher);
};

template<class T>
inline Set<T>::Set(bool(*comparator)(T, T)) : ArrayList<T>() {
	this->comparator = comparator;
}

template<class T>
inline Set<T>::Set() : ArrayList<T>() {
	this->comparator = Set::defaultComparator;
}

template<class T>
inline T Set<T>::search(bool(*identificator)(T)) {
	for (int i = 0; i < this->size(); i++) {
		if (identificator(this->get(i))) {
			return this->get(i);
		}
	}
	throw NoObjectFoundException();
}

template<class T>
inline void Set<T>::add(const T object) {
	size_t position = this->searchPosition(object);
	if (position == this->size()) {
		ArrayList<T>::add(object);
	}
	else {
		ArrayList<T>::add(object, position);
	}
}

template<class T>
inline size_t Set<T>::searchPosition(T object) {
	if (this->size() != 0) {
		return searchPosition(object, 0, this->size() - 1);
	}
	else {
		return 0;
	}
}

template<class T>
inline size_t Set<T>::searchPosition(T& object, size_t begin, size_t end) {
	if (begin > end) {
		throw IncorrectRangeException();
	}
	if (end - begin <= 1) {
		size_t pos = 0;
		switch (pos){
			case 0:
				if (this->comparator(object, this->get(end))) {
					return end;
				}
				else {
					return end + 1;
				}
				break;
			case 1:
				if (this->comparator(object, this->get(end))) {
					return searchPosition(object, begin, begin);
				}
				else {
					return searchPosition(object, end, end);
				}
				break;
		}
	}
	size_t middle = begin + (end - begin) / 2 + 1;
	if (middle == end) {
		middle--;
	}
	if (this->comparator(object, this->get(middle))) {
		return searchPosition(object, begin, middle);
	}
	else {
		return searchPosition(object, middle, end);
	}
}

template<class T>
inline bool Set<T>::defaultComparator(T less, T higher) {
	return less < higher;
}
