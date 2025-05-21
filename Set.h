#pragma once
#include "BinaryTree.h"
#include <functional>
template <typename T>
class Set {
private:
    BinaryTree<T> tree;

public:
    Set() = default;
    Set(const T* items, int count) {
        for (int i = 0; i < count; ++i) {
            insert(items[i]);
        }
    }
    Set(const ArraySequence<T>& arr) {
        for (int i = 0; i < arr.GetLength(); ++i) {
            insert(arr[i]);
        }
    }
    Set(const Set<T>& other) : tree(other.tree) {}
    Set(const BinaryTree<T>& other) : tree(other) {}
    Set(const BinaryTree<T>* other) : tree(other) {}

    Set<T>* insert(const T& item) {
        tree.add(item);
        return this;
    }
    Set<T>* remove(const T& item) {
        tree.remove(item);
        return this;
    }
    bool contains(const T& item) const {
        return tree.contains(item);
    }
    Set<T>* unionWith(const Set<T>& other) const {
        Set<T>* result=new Set<T>(*this);
        auto elements = other.toSequence();
        for (int i = 0; i < elements->GetLength(); ++i) {
            result->insert(elements->Get(i));
        }

        delete elements;
        return result;
    }
    Set<T>* intersectionWith(const Set<T>& other) const {
        Set<T>* result=new Set<T>;
        auto elements = this->toSequence();

        for (int i = 0; i < elements->GetLength(); ++i) {
            if (other.contains(elements->Get(i))) {
                result->insert(elements->Get(i));
            }
        }

        delete elements;
        return result;
    }
    Set<T>* differenceWith(const Set<T>& other) const {
        Set<T>* result=new Set<T>;
        auto elements = this->toSequence();

        for (int i = 0; i < elements->GetLength(); ++i) {
            if (!(other.contains(elements->Get(i)))) {
                result->insert(elements->Get(i));
            }
        }

        delete elements;
        return result;
    }
    bool isSubsetOf(const Set<T>& other) const {
        auto elements = this->toSequence();

        for (int i = 0; i < elements->GetLength(); ++i) {
            if (!other.contains(elements->Get(i))) {
                delete elements;
                return false;
            }
        }

        delete elements;
        return true;
    }

    Sequence<T>* toSequence() const {
        return tree.LNR();
    }
    int size() const {
        return tree.getNodeCount();
    }
    bool isEmpty() const {
        return tree.isEmpty();
    }

    template <typename U>
    Set<U>* map(std::function<U(const T&)> func) const {
        Set<U>* result =new Set<U>(tree.map(func));
        return result;
    }

    Set<T>* where(std::function<bool(const T&)> predicate) const {
        Set<T>* result=new Set<T>(*tree.where(predicate));
        return result;
    }

    T reduce(std::function<T(const T&, const T&)> func, const T& initial) const {
        return tree.Reduce(func, initial);
    }
    void print() const {
        tree.printTree();
    }
    bool operator==(const Set<T>& other) const {
        if (size() != other.size()) {
            return false;
        }
        Sequence<T>* seq1 = toSequence();
        Sequence<T>* seq2 = other.toSequence();

        for (int i = 0; i < seq1->GetLength(); ++i) {
            if (seq1->Get(i) != seq2->Get(i)) {
                delete seq1;
                delete seq2;
                return false;
            }
        }

        delete seq1;
        delete seq2;
        return true;
    }
};
