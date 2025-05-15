#pragma once
#include "ArraySequence.h"

template <typename T>
class ImmutableArraySequence : public ArraySequence<T> {
public:
    ImmutableArraySequence() : ArraySequence<T>() {}
    ImmutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {}
    ImmutableArraySequence(const ImmutableArraySequence<T>& other) : ArraySequence<T>(other) {}
    ImmutableArraySequence(const DynamicArray<T>& arr) : ArraySequence<T>(arr) {}

    ImmutableArraySequence<T>* Instance() {
        return new ImmutableArraySequence(*this);
    }
    ImmutableArraySequence<T>* Set(T value, int index) override {
        ImmutableArraySequence<T>* result = Instance();
        result->array.Set(value, index);
        return result;
    }
    ImmutableArraySequence<T>* Append(T item) override {
        ImmutableArraySequence<T>* result = Instance();
        result->array.Append(item);  // Доступ через область видимости
        return result;
    }
    ImmutableArraySequence<T>* Prepend(T item) override {
        ImmutableArraySequence<T>* result = Instance();
        result->array.Prepend(item);
        return result;
    }
    ImmutableArraySequence<T>* InsertAt(T item, int index) override {
        ImmutableArraySequence<T>* result = Instance();
        result->array.InsertAt(item, index);
        return result;
    }
};