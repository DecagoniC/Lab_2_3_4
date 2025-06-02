#pragma once
#include "ListSequence.h"

template <typename T>
class Stack : private ListSequence<T> {
public:
    Stack() : ListSequence<T>() {}
    Stack(T* items, int count) : ListSequence<T>(items, count) {}
    Stack(const Stack<T>& other) : ListSequence<T>(other) {}
    Stack(const ListSequence<T>& list) : ListSequence<T>(list) {}

    void Push(const T& item) {
        this->Append(item);
    }
    void Pop() {
        if (this->IsEmpty()) throw std::out_of_range("Stack is empty");
        this->RemoveAt(this->GetLength() - 1);
    }
    T Top() const {
        if (this->IsEmpty()) throw std::out_of_range("Stack is empty");
        return this->GetLast();
    }
    bool IsEmpty() const {
        return this->GetLength() == 0;
    }
    bool GetCount() const {
        return this->GetLength();
    }
    Stack<T>* Where(bool (*predicate)(T)) const {
        Sequence<T>* filtered = ListSequence<T>::Where(predicate);
        Stack<T>* result = new Stack<T>(*dynamic_cast<ListSequence<T>*>(filtered));
        delete filtered;
        return result;
    }
    template <typename U>
    Stack<U>* Map(Func_T<T> func) const {
        Sequence<U>* mapped = ListSequence<T>::Map(func);
        Stack<U>* result = new Stack<U>(*dynamic_cast<ListSequence<U>*>(mapped));
        delete mapped;
        return result;
    }
    T Reduce(Func_T_T<T> func, T start) const {
        return ListSequence<T>::Reduce(func, start);
    }
    Stack<T>* Concat(Stack<T>& other) const {
        Sequence<T>* concatenated = this->ListSequence<T>::Concat(static_cast<ListSequence<T>*>(&other));
        Stack<T>* result = new Stack<T>(*dynamic_cast<ListSequence<T>*>(concatenated));
        delete concatenated;
        return result;
    }

    using ListSequence<T>::Get;
    using ListSequence<T>::GetLength;
    using ListSequence<T>::To_String;

    void Print() const {
        this->To_String();
    }
    using ListSequence<T>::To_PrettyString;
    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        os << static_cast<const ListSequence<T>&>(stack);
        return os;
    }
};