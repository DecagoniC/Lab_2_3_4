#pragma once
#include "ArraySequence.h"

template <typename T>
class MutableArraySequence : public ArraySequence<T> {
public:
    MutableArraySequence() : ArraySequence<T>() {}
    MutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {}
    MutableArraySequence(const MutableArraySequence<T>& other) : ArraySequence<T>(other) {}
    MutableArraySequence(DynamicArray<T>* arr) : ArraySequence<T>(arr) {}

    MutableArraySequence<T>* Instance() {
        return this;
    }
    MutableArraySequence<T>* Set(T value, int index)override {
        MutableArraySequence<T>* result = Instance();
        result->array.Set(value, index);
        return result;
    }
    MutableArraySequence<T>* Append(T item)override {
        MutableArraySequence<T>* result = Instance();
        result->array.Append(item);
        return result;
    }
    MutableArraySequence<T>* Prepend(T item)override {
        MutableArraySequence<T>* result = Instance();
        result->array.Prepend(item);
        return result;
    }
    MutableArraySequence<T>* InsertAt(T item, int index)override {
        MutableArraySequence<T>* result = Instance();
        result->array.InsertAt(item, index);
        return result;
    }



};