#pragma once
#include "List.h"

template <class T>
class LinkedListNode : public Object {
public:
	LinkedListNode<T>* next;
	T data;
public:
	LinkedListNode(T data);
};


template <class T>
class LinkedList : public List<T> {
protected:
	LinkedList<T>* tail;
	LinkedList<T>* head;
public:
	LinkedList();
	LinkedList(const LinkedList <T>&reference);
	T get(size_t index) const;
	void add(T object);
	void clear();
	size_t size();
private:
	void setHead(LinkedList<T> head);
};

template<class T>
inline LinkedList<T>::LinkedList() {
	this->next = nullptr;
	this->tail = nullptr;
	this->head = this;
}

template<class T>
inline T LinkedList<T>::get(size_t index) const {
	LinkedList<T>* position = this->head;
	for (int i = 0; position && i < index; i++) {
		position = position->next;
	}
	if (!position) {
		throw 1;
	}
	return position;
}

template<class T>
inline void LinkedList<T>::setHead(LinkedList<T> head) {
	this->head = head;
}

template<class T>
inline LinkedListNode<T>::LinkedListNode(T data) {
	this->data = data;
}
