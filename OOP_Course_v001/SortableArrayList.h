#pragma once
#include "ArrayList.h"
#include <algorithm>
template <class T>
class SortableArrayList : public ArrayList<T> {
public:
	SortableArrayList() : ArrayList<T>() {}
	~SortableArrayList() {}
	void sortBubble(bool (*comp_callback)(T left, T right));
	void sortQuick(bool (*comp_callback)(T left, T right));
private:
	void swap(size_t from, size_t to);
};

template<class T>
inline void SortableArrayList<T>::sortBubble(bool (*comp_callback)(T left, T right)) {
	try {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 1; i < this->size(); i++) {
				if (comp_callback(this->get(i - 1), this->get(i))) {
					this->swap(i - 1, i);
					sorted = false;
				}
			}
		}
	} catch (...) {

	}
}

template<class T>
inline void SortableArrayList<T>::sortQuick(bool (*comp_callback)(T left, T right)) {
	try {
		size_t sz = sizeof(T**);
		int temp1 = (int)(this->data);
		int temp2 = (int)(this->data + this->size());
		int temp3 = temp2 - temp1;
		sort(this->data, this->data + this->len, [=](T* left, T* right) -> bool {return !comp_callback(*left, *right); });
  	} catch(...) {

	}
}

template<class T>
inline void SortableArrayList<T>::swap(size_t from, size_t to) {
	T* from_ptr = this->get_ptr(from);
	T* to_ptr = this->get_ptr(to);
	T temp = *from_ptr;
	*from_ptr = *to_ptr;
	*to_ptr = temp;
}

