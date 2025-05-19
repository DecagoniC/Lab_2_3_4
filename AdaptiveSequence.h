#pragma once
#include "Sequence.h"
#include <iostream>

template<typename T>
class AdaptiveSequence : public Sequence<T> {
private:
    T* data;
    int correct;
    int length;
    int capacity;
public:
    AdaptiveSequence() : data(nullptr), length(0), capacity(0), correct(0) {}
    AdaptiveSequence(int size) : capacity(size), length(size), correct(0) {
        if (size < 0) {
            throw std::out_of_range("Size cannot be negative");
        }
        if (size == 0) {
            data = nullptr;
        }
        else {
            data = new T[size];
            correct = (size - length) / 2;
            for (int i = 0; i < size; i++) {
                data[i] = T();
            }
        }
    }
    AdaptiveSequence(T* items, int size) : data(new T[size]), capacity(size), length(size), correct(0) {
        correct = (size - length) / 2;
        for (int i = 0; i < size; i++) {
            if (i < correct || i >= correct + length) {
                data[i] = T();
            }
            else {
                data[i] = items[i - correct];
            }
        }
    }
    AdaptiveSequence(const AdaptiveSequence<T>& other) : data(new T[other.capacity]), length(other.length), capacity(other.capacity), correct(other.correct) {
        for (int i = 0; i < capacity; i++) {
            data[i] = other.data[i];
        }
    }
    ~AdaptiveSequence() {
        delete[] data;
    }

    T Get(int index) const override {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        int actualIndex = index + correct;
        if (actualIndex < 0 || actualIndex >= capacity) {
            throw std::out_of_range("Index + correct out of bounds");
        }
        return data[actualIndex];
    }
    T GetLast() const override {
        return Get(length - 1);
    }
    T GetFirst() const override {
        return Get(0);
    }
    int GetLength() const override {
        return length;
    }
    int GetCapacity() const {
        return capacity;
    }
    void To_String() const override {
        static_assert(
            std::is_same_v<decltype(std::declval<std::ostream&>() << std::declval<T>()), std::ostream&>,
            "T must be printable with std::ostream"
            );
        if (length == 0) {
            std::cout << "[]\n";
            return;
        }
        std::cout << "[";
        for (int i = 0; i < length; i++) {
            std::cout << Get(i);
            if (i < length - 1) {
                std::cout << "; ";
            }
        }
        std::cout << "]\n";
    }
    void To_String_All() const {
        if (capacity == 0) {
            std::cout << "[]\n";
            return;
        }
        std::cout << "[";
        for (int i = 0; i < capacity; i++) {
            std::cout << data[i];
            if (i < capacity - 1) {
                std::cout << "; ";
            }
        }
        std::cout << "]\n";
    }
    int GetCorrect() const {
        return correct;
    }
    AdaptiveSequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex >= length || startIndex > endIndex) {
            throw std::out_of_range("Invalid subsequence range");
        }
        AdaptiveSequence<T>* subArr = new AdaptiveSequence<T>(0);
        for (int i = startIndex; i <= endIndex; i++) {
            subArr->Append(Get(i));
        }
        return subArr;
    }
    AdaptiveSequence<T>* Set(T value, int index) override {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        int actualIndex = index + correct;
        if (actualIndex < 0 || actualIndex >= capacity) {
            throw std::out_of_range("Index + correct out of bounds");
        }
        data[actualIndex] = value;
        return this;
    }
    AdaptiveSequence<T>* InsertAt(T item, int index) override {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of bounds");
        }
        if (correct + length >= capacity) {
            Resize(std::max(1, 2 * capacity));
        }
        for (int i = length - 1; i >= index; i--) {
            data[correct + i + 1] = data[correct + i];
        }
        data[correct + index] = item;
        length++;
        return this;
    }
    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::out_of_range("Size cannot be negative");
        }
        T* newData = new T[newSize];
        int copySize = std::min(length, newSize);
        int newCorrect = (newSize - copySize) / 2;

        if (copySize > 0) {
            for (int i = 0; i < newCorrect; i++) {
                newData[i] = T();
            }
            for (int i = 0; i < copySize; i++) {
                newData[newCorrect + i] = data[correct + i];
            }
            for (int i = newCorrect + copySize; i < newSize; i++) {
                newData[i] = T();
            }
        }
        else {
            newCorrect = newSize / 2;
            for (int i = 0; i < newSize; i++) {
                newData[i] = T();
            }
        }

        delete[] data;
        data = newData;
        capacity = newSize;
        correct = newCorrect;
    }
    AdaptiveSequence<T>* Append(T value) override {
        if (correct + length >= capacity) {
            int newSize = (capacity == 0) ? 1 : 2 * capacity;
            Resize(newSize);
            while (correct + length >= capacity) {
                newSize = 2 * capacity;
                Resize(newSize);
            }
        }
        data[correct + length] = value;
        length++;
        return this;
    }
    AdaptiveSequence<T>* Prepend(T value) override {
        if (correct <= 0 || length >= capacity) {
            int newSize = (capacity == 0) ? 1 : 2 * capacity;
            Resize(newSize);
            while (correct <= 0) {
                newSize = 2 * capacity;
                Resize(newSize);
            }
        }
        correct--;
        data[correct] = value;
        length++;
        return this;
    }
    AdaptiveSequence<T>* Concat(Sequence<T>* other) const override {
        AdaptiveSequence<T>* result = new AdaptiveSequence<T>(0);
        for (int i = 0; i < length; i++) {
            result->Append(Get(i));
        }
        for (int i = 0; i < other->GetLength(); i++) {
            result->Append(other->Get(i));
        }
        return result;
    }
    AdaptiveSequence<T>* Map(Func_T<T> func) const override {
        AdaptiveSequence<T>* result = new AdaptiveSequence<T>(0);
        for (int i = 0; i < length; i++) {
            result->Append(func(Get(i)));
        }
        return result;
    }
    AdaptiveSequence<T>* Where(Func_T_bool<T> predicate) const override {
        AdaptiveSequence<T>* result = new AdaptiveSequence<T>(0);
        for (int i = 0; i < length; i++) {
            if (predicate(Get(i))) {
                result->Append(Get(i));
            }
        }
        return result;
    }
    T Reduce(Func_T_T<T> func, T start) const override {
        T result = start;
        for (int i = 0; i < length; i++) {
            result = func(result, Get(i));
        }
        return result;
    }

    T& operator[](int index) {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index + correct];
    }
    const T& operator[](int index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index + correct];
    }
    friend std::ostream& operator<<(std::ostream& os, const AdaptiveSequence<T>& arr) {
        os << "[";
        for (int i = 0; i < arr.length; i++) {
            os << arr.Get(i);
            if (i < arr.length - 1) {
                os << "; ";
            }
        }
        os << "]";
        return os;
    }
};