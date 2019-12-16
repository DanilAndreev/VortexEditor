#pragma once
#include "Set.h"

template <class T>
class HashSetNode {
	T value;
	size_t key;
	HashSetNode(size_t key, T value) : value(value), key(key) {}
	HashSetNode();
};



template <class T>
class HashSet : public Set<HashSetNode<T>> {
public:
	HashSet() : Set<HashSetNode<T>>(comparator) {}
	~HashSet() {}
	virtual void add(const T object);
	virtual T get(const size_t hash) const;
protected:
	static bool comparator(HashSetNode<T> &less, HashSetNode<T> &higher) {
		return less.key < higher.key;
	}
};

template<class T>
inline void HashSet<T>::add(const T object) {
	Set<HashSetNode<T>>::add(HashSetNode<T>());
}

template<class T>
inline T HashSet<T>::get(const size_t hash) const
{
	return T();
}
