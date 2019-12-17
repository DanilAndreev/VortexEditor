#pragma once

#include "Object.h"
#include "Exception.h"
#include <set>
#include <type_traits>
namespace {
	template <class T>
	class HashSetNode : public Object {
	public:
		T value;
		size_t key;
		HashSetNode(size_t key, T value) : value(value), key(key) {}
		HashSetNode() : HashSetNode(0, T()) {}
	};
}

template <class T>
class HashSet : protected set<HashSetNode<T>, bool(*)(const HashSetNode<T>& less, const HashSetNode<T>& higher)>, public Object{
	typedef set<HashSetNode<T>, bool(*)(const HashSetNode<T>& less, const HashSetNode<T>& higher)> Set;
public:
	HashSet() : Set(&comparator) {}
	HashSet(const HashSet& reference) : Set(reference), Object(reference){}
	~HashSet() {}
	virtual void add(size_t key, T element);
	virtual T get(const size_t key) const;
	using Set::cend;
	using Set::cbegin;
	using Set::size;
	using Set::operator=;
	using Set::find;
	using Set::empty;
	using Set::max_size;
	using Set::clear;
	using Set::erase;
protected:
	static bool comparator(const HashSetNode<T>& less, const HashSetNode<T>& higher) {
		return less.key < higher.key;
	}
};

template<class T>
inline void HashSet<T>::add(size_t key, T element) {
	this->insert(HashSetNode<T>(key, element));
}

template<class T>
inline T HashSet<T>::get(const size_t key) const {
	if (!this->count(HashSetNode<T>(key, T()))) {
		throw NoObjectFoundException();
	}
	return this->find(HashSetNode<T>(key, T()))->value;
}

