#pragma once
#include "ListSequence.h"
template <typename T>
class Stack: protected ListSequence<T> {
public:
	Stack() : ListSequence() {}
	Stack(int count) : ListSequence(count) {}
	Stack(T* items, int count) : ListSequence(items,count)) {}
	Stack(const Stack<T>& other) : ListSequence(other) {}
	Stack(const LinkedList<T>& list) : ListSequence(list) {}
	~Stack() = default;
	bool Is_empty() {
		return (!this->list.GetLength());
	}
	T Top() {
		return this->GetFirst();
	}
	void Pop() {
		ListSequence<T>::PopFront();
	}
	Sequence<T>* Add(T item){
		ListSequence<T>::Append(item);
		return this;
	}
	void To_String() {
		ListSequence<T>::To_String();
		return;
	}
};