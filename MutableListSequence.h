#pragma once
#include "ListSequence.h"

template <typename T>
class MutableListSequence : public ListSequence<T> {
public:
    MutableListSequence() : ListSequence<T>() {}
    MutableListSequence(T* items, int count) : ListSequence<T>(items, count) {}
    MutableListSequence(const MutableListSequence<T>& other) : ListSequence<T>(other) {}
    explicit MutableListSequence(LinkedList<T>* arr) : ListSequence<T>(arr) {}

    MutableListSequence<T>* Instance() {
        return this;
    }
    MutableListSequence<T>* Set(int index, T value)override {
        MutableListSequence<T>* result = Instance();
        result->list.Set(index, value);
        return result;
    }
    MutableListSequence<T>* Append(T item)override {
        MutableListSequence<T>* result = Instance();
        result->list.Append(item);
        return result;
    }
    MutableListSequence<T>* Prepend(T item)override {
        MutableListSequence<T>* result = Instance();
        result->list.Prepend(item);
        return result;
    }
    MutableListSequence<T>* InsertAt(T item, int index)override {
        MutableListSequence<T>* result = Instance();
        result->list.InsertAt(item, index);
        return result;
    }



};