#pragma once
#include <stdexcept>
#include <iostream>



template <typename T>
class LinkedList {
protected:
    
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
        Node(T val, Node* ptr) : value(val), next(ptr) {}
    };
    Node* head;
    Node* tail;
    int length;
public:
    using NodeType = Node;
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}
    LinkedList(T* items, int count) : head(nullptr), tail(nullptr), length(0) {
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }
    LinkedList(int count) : head(nullptr), tail(nullptr), length(0) {
        for (int i = 0; i < count; i++) {
            Append(T());
        }
    }
    LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), length(0) {
        Node* current = other.head;
        while (current) {
            Append(current->value);
            current = current->next;
        }
    }
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            PopFront();
            return;
        }

        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }

        Node* toDelete = prev->next;
        prev->next = toDelete->next;

        if (toDelete == tail) {
            tail = prev;
        }

        delete toDelete;
        length--;
    }




    T GetFirst() const {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        return head->value;
    }
    T GetLast() const {
        if (!tail) {
            throw std::out_of_range("List is empty");
        }
        return tail->value;
    }
    T Get(int index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    void PopFront() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        Node* tmp = head;
        length--;
        head = head->next;
        delete tmp;
    }
    int GetLength() const {
        return length;
    }
    void To_String() const { 
        if (length != 0) std::cout << "[";
        else std::cout << "[]\n";
        for (int i = 0; i < GetLength(); i++) {
            if (i == GetLength() - 1) {
                std::cout << Get(i) << "]\n";
            }
            else {
                std::cout << Get(i) << "; ";
            }
        }
    }
    LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
        if (startIndex > endIndex || endIndex >= length) {
            throw std::out_of_range("Invalid range");
        }
        LinkedList<T>* subList = new LinkedList<T>;
        for (int i = startIndex; i <= endIndex; i++) {
            subList->Append(Get(i));
        }
        return subList;
    }
    void Set(T item, int ind) {
        Node* current = head;
        for (int i = 0; i < ind; i++) {
            current = current->next;
        }
        current->value = item;
    }
    void Append(T item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = newNode;
            tail = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void Prepend(T item) {
        head = new Node(item, head);
        if (!tail) {
            tail = head;
        }
        length++;
    }
    void InsertAt(T item, int index) {
        if (index > length) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            Prepend(item);
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            current->next = new Node(item, current->next);
            length++;
        }
    }
    LinkedList<T>* Concat(const LinkedList<T>& list) const {
        LinkedList<T>* result = new LinkedList<T>(*this);
        for (int i = 0; i < list.GetLength(); i++) {
            result->Append(list.Get(i));
        }
        return result;
    }
    T& operator[](int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    const T& operator[](int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) {
            return *this;
        }
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        length = 0;
        Node* current = other.head;
        while (current) {
            Append(current->value);
            current = current->next;
        }
        return *this;
    }
};
