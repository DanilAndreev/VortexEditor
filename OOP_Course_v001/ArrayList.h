#pragma once
#include "List.h"
#include "Exception.h"
#include <memory>

template <class T>
class ArrayList : public List<T> {
protected:
	T** data;
	size_t len;
public:
	ArrayList();
	~ArrayList();
	ArrayList(const ArrayList& reference);
	virtual void add(const T object);
	virtual T get(size_t index) const;
	virtual void clear();
	virtual size_t size();
public:
	void operator=(const ArrayList& right);
protected:
	virtual void add(const T object, size_t index);
	virtual T* get_ptr(size_t index) const;
};

template<class T>
ArrayList<T>::ArrayList() {
	this->len = 0;
	this->data = nullptr;
}

template<class T>
ArrayList<T>::~ArrayList() {
	this->clear();
}

template<class T>
inline ArrayList<T>::ArrayList(const ArrayList& reference) {
	this->len = reference.len;
	if (!len) {
		this->data = nullptr;
		return;
	}
	T** temp = new T * [this->len];
	for (size_t i = 0; i < this->len; i++) {
		temp[i] = new T;
		*(temp[i]) = reference.get(i);
	}
	this->data = temp;
}

template<class T>
inline void ArrayList<T>::add(const T object) {
/*
	size_t newlen = this->len + 1;
	T** temp = new T*[newlen];
	if (this->data) {
		memcpy(temp, this->data, (newlen - 1) * sizeof(T*));
	}
	temp[newlen - 1] = new T;
	*(temp[newlen - 1]) = object;
	if (this->data) {
		delete[] this->data;
	}
	this->len = newlen;
	this->data = temp;
*/
	this->add(object, this->len);
}

template<class T>
inline void ArrayList<T>::clear() {
	if (this->data) {
		for (size_t i = 0; i < this->len; i++) {
			delete this->data[i];
		}
		delete[] this->data;
	}
	this->data = nullptr;
	this->len = 0;
}

template<class T>
inline T ArrayList<T>::get(size_t index) const{
	return *(this->get_ptr(index));
}

template<class T>
inline size_t ArrayList<T>::size() {
	return this->len;
}

template<class T>
inline void ArrayList<T>::operator=(const ArrayList& right) {
	this->clear();
	this->len = right.len;
	if (!len) {
		this->data = nullptr;
		return;
	}
	T** temp = new T*[this->len];
	for (size_t i = 0; i < this->len; i++) {
		temp[i] = new T;
		*(temp[i]) = right.get(i);
	}
	this->data = temp;
}

template<class T>
inline T* ArrayList<T>::get_ptr(size_t index) const {
	if (len <= 0) {
		throw IndexOutOfBoundsException();
	}
	if (index >= len) {
		throw IndexOutOfBoundsException();
	}
	return this->data[index];
}

template<class T>
inline void ArrayList<T>::add(const T object, size_t index) {
	size_t newlen = this->len + 1;
	T** temp = new T * [newlen];
	if (this->data) {
		memcpy(temp, this->data, (index) * sizeof(T*));
		memcpy(temp + index + 1, this->data + index, (newlen - 1 - index) * sizeof(T*));
	}

	temp[index] = new T;
	*(temp[index]) = object;
	if (this->data) {
		delete[] this->data;
	}
	this->len = newlen;
	this->data = temp;
}



