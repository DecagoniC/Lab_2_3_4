#pragma once
#include "LinkedList.h"
#include "Sequence.h"
template <typename T>
class ListSequence : public Sequence<T> {
protected:
    LinkedList<T> list;
    ListSequence(LinkedList<T>* lst) : list(*lst) {}
public:
    ListSequence() : list(LinkedList<T>()) {}
    ListSequence(int count) : list(LinkedList<T>(count)) {}
    ListSequence(T* items, int count) : list(LinkedList<T>(items, count)) {}
    ListSequence(const ListSequence<T>& other) : list(LinkedList<T>(other.list)) {}
    ListSequence(const LinkedList<T>& list) : list(list) {}
    ~ListSequence() = default;

    void RemoveAt(int index) {
        if (index < 0 || index >= list.GetLength()) {
            throw std::out_of_range("Index out of range");
        }
        list.RemoveAt(index);
    }





    T GetFirst() const override {
        return list.GetFirst();
    }
    T GetLast() const override {
        return list.GetLast();
    }
    T Get(int index) const override {
        return list.Get(index);
    }
    int GetLength() const override {
        return list.GetLength();
    }
    void To_String()const override {
        list.To_String();
    }
    Sequence<T>* PopFront() {
        list.PopFront();
        return this;
    }
    Sequence<T>* GetSubsequence(int start, int end) const override {
        LinkedList<T>* sublist = list.GetSubList(start, end);
        ListSequence<T>* result = new ListSequence<T>(*sublist);
        delete sublist;
        return result;
    }
    Sequence<T>* Concat(Sequence<T>* other) const {
        ListSequence<T>* result = new ListSequence<T>(*this);
        for (int i = 0; i < other->GetLength(); i++) {
            result->Append(other->Get(i));
        }
        return result;
    }
    int GetCapacity() {
        return list.GetCapacity();
    }
    Sequence<T>* Set(T value,int index )override {
        this->list.Set(value, index);
        return this;
    }
    Sequence<T>* Append(T item)override {
        this->list.Append(item);
        return this;
    }
    Sequence<T>* Prepend(T item)override {
        this->list.Prepend(item);
        return this;
    }
    Sequence<T>* InsertAt(T item, int index)override {
        this->list.InsertAt(item, index);
        return this;
    }
    Sequence<T>* Map(Func_T<T> func) const override {
        ListSequence<T>* result = new ListSequence<T>(*this);
        for (int i = 0; i < list.GetLength(); i++) {
            result->list[i] = func(list[i]);
        }
        return result;
    }
    Sequence<T>* Where(Func_T_bool<T> predicate) const override {
        int count = 0;
        for (int i = 0; i < list.GetLength(); i++) {
            if (predicate(list[i])) {
                count++;
            }
        }
        ListSequence<T>* result = new ListSequence<T>(count);
        int pos = 0;
        for (int i = 0; i < list.GetLength(); i++) {
            if (predicate(list[i])) {
                result->list.Set(list[i], pos);
                pos++;
            }
        }
        return result;
    }
    T Reduce(Func_T_T<T> func, T start) const override {
        T result = start;
        for (int i = 0; i < list.GetLength(); i++) {
            result = func(result, list[i]);
        }
        return result;
    }
    T& operator[](int index) {
        if (index >= list.GetLength()) {
            throw std::out_of_range("Index out of bounds");
        }
        return list[index];
    }
    const T& operator[](int index) const{
        if (index >= list.GetLength()) {
            throw std::out_of_range("Index out of bounds");
        }
        return list[index];
    }
};
