#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include <stdexcept>
#include <functional>

template <typename T>
class SegmentedList : public Sequence<T> {
private:
    int segLen;
    int len;
    struct Segment {
        DynamicArray<T> value;
        int storage;
        Segment(int segLen) : value(segLen), storage(0) {}
        Segment(T* data, int len, int segLen) {
            if (len < 0 || len > segLen) throw std::out_of_range("Invalid length");
            value = DynamicArray<T>(segLen);
            for (int i = 0; i < len; ++i) {
                value.Set(data[i], i);
            }
            storage = len;
        }
        ~Segment() = default;
    };
    LinkedList<Segment> data;
    void AddSegment() {
        Segment newSeg(segLen);
        data.Append(newSeg);
    }
    void AddSegment(int len) {
        Segment newSeg(segLen);
        newSeg.storage = len;
        data.Append(newSeg);
        this->len + len;
    }
    void AddSegment(T* data, int len) {
        Segment newSeg(data, len, segLen);
        this->len= +len;
        this->data.Append(newSeg);
        this->len + len;
    }
    void AddSegment(Segment& seg) {
        data.Append(seg);
        len = len + seg.storage;
    }

public:
    SegmentedList() : segLen(4) {
        AddSegment();
    }
    SegmentedList(LinkedList<Segment> ndata): data(ndata) {
    }
    SegmentedList(T* data, int length) : segLen(4) {
        if (length < 0) throw std::invalid_argument("Negative length");
        if (!data && length > 0) throw std::invalid_argument("Null data");
        int remaining = length;
        int pos = 0;
        while (remaining > 0) {
            int toCopy = std::min(remaining, segLen);
            AddSegment(data + pos, toCopy);
            remaining -= toCopy;
            pos += toCopy;
        }
        len = length;
    }
    SegmentedList(const SegmentedList<T>& other) : segLen(other.segLen),len(other.len) {
        for (int i = 0; i < other.data.GetLength(); ++i) {
            Segment seg = other.data[i];
            this->data.Append(seg);
        }
    }
    SegmentedList(const DynamicArray<T>& other, int len, int segSize) : segLen(segSize), len(len) {
        AddSegment();
        for (int i = 0; i < other.GetLength(); ++i) {
            Append(other[i]);
        }
    }
    SegmentedList(int len,int segSize) : segLen(segSize),len(len) {
        if (len < 1) throw std::invalid_argument("SegmentedList size must be at least 1");
        int counter=len;
        for (int i = counter; i > 0; i=i - segLen) {
            AddSegment(i>segLen ? segLen:i);
        }
    }
    ~SegmentedList() = default;
    Sequence<T>* Append(T item) override {
        Segment& last = data[data.GetLength() - 1];
        if (last.storage < segLen) {
            last.value.Set(item, last.storage);
            last.storage++;
        }
        else {
            AddSegment();
            Segment& newLast = data[data.GetLength() - 1];
            newLast.value.Set(item, 0);
            newLast.storage = 1;
        }
        len++;
        return this;
    }
    int GetLength() const override {
        return len;
    }
    T Get(int index) const override {
        if (index < 0 || index >= GetLength()) throw std::out_of_range("Index out of range");
        int curr = 0;
        for (int i = 0; i < data.GetLength(); ++i) {
            if (curr + data[i].storage > index) {
                return data[i].value.Get(index - curr);
            }
            curr += data[i].storage;
        }
    }
    T GetFirst() const override { 
        return Get(0);
    }
    T GetLast() const override {
        return Get(len-1);
    }
    Sequence<T>* Set(T item, int index) override {
        if (index < 0 || index > len-1) {
            throw std::out_of_range("Index out of bounds");
        }
        Segment& curr = data[index/segLen];
        if (curr.storage >= index - segLen * (index / segLen)) {
            curr.value.Set(item, index - segLen * (index / segLen));
        }
        else{
            curr = data[index / segLen + 1];
            curr.value.Set(item, index - segLen * (index / segLen)); 
        }
        return this;
    }
    Sequence<T>* Prepend(T item) override {
        Segment& last = data[data.GetLength() - 1];
        if (last.storage < segLen) {
            last.value.InsertAt(item, 0);
            last.storage++;
        }
        else {
            AddSegment();
            Segment& newLast = data[data.GetLength() - 1];
            newLast.value.InsertAt(item, 0);
            newLast.storage = 1;
        }
        len++;
        return this;
    }
    Sequence<T>* InsertAt(T item, int index) override {
        if (index < 0 || index >= GetLength()) throw std::out_of_range("Index out of range");
        int curr = 0;
        for (int i = 0; i < data.GetLength(); ++i) {
            Segment& seg = data[i];
            if (curr + seg.storage >= index) {
                int localIndex = index - curr;
                DynamicArray<T>& arr = seg.value;
                if (seg.storage < segLen) {
                    DynamicArray<T> newArr(segLen);
                    for (int j = 0; j < localIndex; ++j) {
                        newArr.Set(arr.Get(j), j);
                    }
                    newArr.Set(item, localIndex);
                    for (int j = localIndex; j < seg.storage; ++j) {
                        newArr.Set(arr.Get(j), j + 1);
                    }
                    seg.value = newArr;
                    seg.storage++;
                }
                else {
                    DynamicArray<T> leftArr(segLen);
                    DynamicArray<T> rightArr(segLen);
                    int leftCount = localIndex;
                    int rightCount = 0;
                    for (int j = 0; j < localIndex; ++j) {
                        leftArr.Set(arr.Get(j), j);
                    }
                    leftArr.Set(item, localIndex);
                    leftCount++;
                    for (int j = localIndex; j < seg.storage; ++j) {
                        if (leftCount < segLen) {
                            leftArr.Set(arr.Get(j), leftCount);
                            leftCount++;
                        }
                        else {
                            rightArr.Set(arr.Get(j), rightCount);
                            rightCount++;
                        }
                    }
                    seg.value = leftArr;
                    seg.storage = leftCount;
                    if (rightCount > 0) {
                        Segment rightSeg(segLen);
                        rightSeg.value = rightArr;
                        rightSeg.storage = rightCount;
                        data.InsertAt(rightSeg, i + 1);
                        i++;
                    }
                }
                len++;
                bool merged;
                do {
                    merged = false;
                    for (int j = 1; j < data.GetLength(); ++j) {
                        Segment& current = data[j];
                        Segment& prev = data[j - 1];
                        if (prev.storage + current.storage <= segLen) {
                            DynamicArray<T> newArr(segLen);
                            int newCount = 0;
                            for (int k = 0; k < prev.storage; ++k) {
                                newArr.Set(prev.value.Get(k), newCount);
                                newCount++;
                            }
                            for (int k = 0; k < current.storage; ++k) {
                                newArr.Set(current.value.Get(k), newCount);
                                newCount++;
                            }
                            prev.value = newArr;
                            prev.storage = newCount;
                            LinkedList<Segment> newData;
                            for (int k = 0; k < data.GetLength(); ++k) {
                                if (k != j) {
                                    newData.Append(data[k]);
                                }
                            }
                            data = newData;
                            merged = true;
                            break;
                        }
                    }
                } while (merged);
                return this;
            }
            curr += seg.storage;
        }
        Append(item);
        return this;
    }
    Sequence<T>* GetSubsequence(int start, int end) const override {
        SegmentedList<int>* result= new SegmentedList<int> (end-start+1,segLen);
        result->To_SegString();
        for (int i = start; i < end+1; ++i) {
            result->To_SegString();
            result->Set(Get(i), i-start);
        }
        return result;
    }
    Sequence<T>* Concat(Sequence<T>* other) const override {
        const SegmentedList<T>* otherList = dynamic_cast<const SegmentedList<T>*>(other);
        if (!otherList) {
            throw std::invalid_argument("Concatenation requires another SegmentedList");
        }
        SegmentedList<T>* result = new SegmentedList<T>();
        result->segLen = this->segLen;
        for (int i = 0; i < this->data.GetLength(); ++i) {
            Segment seg = this->data[i];
            result->AddSegment(seg);
        }
        for (int i = 0; i < otherList->data.GetLength(); ++i) {
            Segment seg = otherList->data[i];
            result->AddSegment(seg);
        }
        result->len = this->len + otherList->len;
        bool merged;
        do {
            merged = false;
            for (int j = 1; j < result->data.GetLength(); ++j) {
                Segment& current = result->data[j];
                Segment& prev = result->data[j - 1];
                if (prev.storage + current.storage <= result->segLen) {
                    DynamicArray<T> newArr(result->segLen);
                    int newCount = 0;
                    for (int k = 0; k < prev.storage; ++k) {
                        newArr.Set(prev.value.Get(k), newCount);
                        newCount++;
                    }
                    for (int k = 0; k < current.storage; ++k) {
                        newArr.Set(current.value.Get(k), newCount);
                        newCount++;
                    }
                    prev.value = newArr;
                    prev.storage = newCount;
                    LinkedList<Segment> newData;
                    for (int k = 0; k < result->data.GetLength(); ++k) {
                        if (k != j) {
                            newData.Append(result->data[k]);
                        }
                    }
                    result->data = newData;
                    merged = true;
                    break;
                }
            }
        } while (merged);
        return result;
    }
    Sequence<T>* Map(Func_T<T> func) const override {
        DynamicArray<T> r(len);
        int counter = 0;
        for (int i = 0; i < len; ++i) {
            T tmp = func(Get(i));
            r.Set(tmp, counter);
            counter++;
        }
        SegmentedList<T>* result = new SegmentedList<T>(r, counter, segLen);
        return result;
    }
    Sequence<T>* Where(Func_T_bool<T> predicate) const override {
        int count = 0;
        for (int i = 0; i < GetLength(); i++) {
            if (predicate(Get(i))) {
                count++;
            }
        }
        SegmentedList<T>* result = new SegmentedList<T>(count,segLen);
        int pos = 0;
        for (int i = 0; i < GetLength(); i++) {
            if (predicate(Get(i))) {
                result->Set(Get(i), pos);
                pos++;
            }
        }
        return result;
    }
    T Reduce(Func_T_T<T> func, T start) const override {
        T result = start;
        for (int i = 0; i < len; i++) {
            result = func(result, data[i/segLen].value[i%segLen]);
        }
        return result;
    }
    void To_String() const override {
        std::cout << "[";
        int totalLength = GetLength();
        int currentIndex = 0;
        for (int i = 0; i < data.GetLength(); ++i) {
            const Segment& seg = data[i];
            for (int j = 0; j < seg.storage; ++j) {
                std::cout << seg.value.Get(j);
                if (currentIndex < totalLength - 1) {
                    std::cout << "; ";
                }
                currentIndex++;
            }
        }
        std::cout << "]" << std::endl;
    }
    void To_SegString() {
        std::cout << "[";
        for (int i = 0; i < data.GetLength(); ++i) {
            data[i].value.To_String_S();
            if (i < data.GetLength()-1) {
                std::cout << "; ";
            }
        }
        std::cout << "]\n";
    }
    T& operator[](int index) {
        if (index >= GetLength()) {
            throw std::out_of_range("Index out of bounds");
        }
        int curr = 0;
        for (int i = 0; i < data.GetLength(); ++i) {
            if (curr + data[i].storage > index) {
                return data[i].value[index - curr];
            }
            curr += data[i].storage;
        }
    }
    const T& operator[](int index) const {
        if (index >= GetLength()) {
            throw std::out_of_range("Index out of bounds");
        }
        int curr = 0;
        for (int i = 0; i < data.GetLength(); ++i) {
            if (curr + data[i].storage > index) {
                return data[i].value[index - curr];
            }
            curr += data[i].storage;
        }
    }
};