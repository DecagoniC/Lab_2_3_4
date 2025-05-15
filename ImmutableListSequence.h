#pragma once
#include "ListSequence.h"

template <typename T>
class ImmutableListSequence : public ListSequence<T> {
public:
    ImmutableListSequence() : ListSequence<T>() {}
    ImmutableListSequence(T* items, int count) : ListSequence<T>(items, count) {}
    ImmutableListSequence(const ImmutableListSequence<T>& other) : ListSequence<T>(other) {}
    explicit ImmutableListSequence(LinkedList<T>* arr) : ListSequence<T>(arr) {}

    ImmutableListSequence<T>* Instance() {
        return new ImmutableListSequence(*this);
    }
    ImmutableListSequence<T>* Set(T value, int index) override {
        if (index < 0 || index >= this->list.GetLength()) {
            throw std::out_of_range("Index out of bounds");
        }
        LinkedList<T>* newList = new LinkedList<T>();
        for (int i = 0; i < this->list.GetLength(); ++i) {
            if (i == index) {
                newList->Append(value);
            }
            else {
                newList->Append(this->list.Get(i));
            }
        }
        return new ImmutableListSequence<T>(newList);
    }
    ImmutableListSequence<T>* Append(T item)override {
        ImmutableListSequence<T>* result = Instance();
        result->list.Append(item);
        return result;
    }
    ImmutableListSequence<T>* Prepend(T item)override {
        ImmutableListSequence<T>* result = Instance();
        result->list.Prepend(item);
        return result;
    }
    ImmutableListSequence<T>* InsertAt(T item, int index)override {
        ImmutableListSequence<T>* result = Instance();
        result->list.InsertAt(item, index);
        return result;
    }



};