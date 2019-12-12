#pragma once
#include "ArrayList.h"

template <class T>
class Set : public ArrayList<T> {
protected:
	bool (*comparator)(T, T);
public:
	Set(const bool (*comparator)(T, T));
	~Set() {}
	Set(const Set& reference) : ArrayList(reference) {}
	virtual T search(const bool (*identificator)(T));
	virtual void add(const T object);
protected:
	size_t searchPosition(T object);
	size_t searchPosition(T object, size_t begin, size_t end);
};

template<class T>
inline Set<T>::Set(const bool(*comparator)(T, T)) : ArrayList<T>() {
	this->comparator = comparator;
}

template<class T>
inline T Set<T>::search(const bool(*identificator)(T)) {
	for (int i = 0; i < this->size(); i++) {
		if (identificator(this->get(i))) {
			return this->get(i);
		}
	}
	throw NoObjectFoundException();
}

template<class T>
inline void Set<T>::add(const T object) {

}

template<class T>
inline size_t Set<T>::searchPosition(T object) {
	

}

template<class T>
inline size_t Set<T>::searchPosition(T object, size_t begin, size_t end) {
	if (begin > end) {
		throw IncorrectRangeException();
	}
	if (end - begin <= 1) {
		return begin;
	}
	size_t middle = (end - begin) / 2;
	if (this->comparator(object, this->get(middle))) {
		return searchPosition(object, begin, middle)
	}
	else {
		return searchPosition(object, middle, end);
	}
}
