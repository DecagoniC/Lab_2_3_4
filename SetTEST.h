#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <functional>
#include "Set.h"
#include "ArraySequence.h"
class Person {
protected:
    std::string name;
    int age;
public:
    Person() : name("nobody"), age(18) {}
    Person(std::string name, int age) : name(name), age(age) {}
    bool operator==(const Person& human) const {
        return name == human.name && age == human.age;
    }
    bool operator>(const Person& human) const {
        return age > human.age;
    }
    bool operator<(const Person& human) const {
        return age < human.age;
    }
};
class Student : public Person {
protected:
    std::string university;
public:
    Student() : Person(), university("SFU") {}
    Student(std::string name, int age, std::string university)
        : Person(name, age), university(university) {
    }
};
struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator>(const Point& other) const {
        if (x != other.x) return x > other.x;
        return y > other.y;
    }
};
void testSetConstructors() {
    std::cout << "=== Set Constructors Testing ===\n";

    // Test 1: Default constructor
    try {
        Set<int> set;
        std::cout << "Test 1: Default constructor - ";
        if (set.isEmpty() && set.size() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Array constructor
    try {
        int items[] = { 1, 2, 3, 4, 5 };
        Set<int> set(items, 5);
        std::cout << "Test 2: Array constructor - ";
        if (set.size() == 5 && set.contains(1) && set.contains(3) && set.contains(5)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: ArraySequence constructor
    try {
        ArraySequence<int> arr;
        arr.Append(10);
        arr.Append(20);
        arr.Append(30);
        Set<int> set(arr);
        std::cout << "Test 3: ArraySequence constructor - ";
        if (set.size() == 3 && set.contains(10) && set.contains(20) && set.contains(30)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Copy constructor
    try {
        Set<int> set1;
        set1.insert(10)->insert(20)->insert(30);
        Set<int> set2(set1);
        std::cout << "Test 4: Copy constructor - ";
        if (set2.size() == 3 && set2.contains(10) && set2.contains(20) && set2.contains(30)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: BinaryTree constructor
    try {
        int items[] = { 4, 6, 9 };
        BinaryTree<int> tree(items, 3);
        Set<int> set(tree);
        std::cout << "Test 5: BinaryTree constructor - ";
        if (set.size() == 3 && set.contains(4) && set.contains(6) && set.contains(9)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: BinaryTree pointer constructor
    try {
        int items[] = { 15, 10, 25 };
        BinaryTree<int>* tree = new BinaryTree<int>(items, 3);
        Set<int> set(tree);
        delete tree;
        std::cout << "Test 6: BinaryTree pointer constructor - ";
        if (set.size() == 3 && set.contains(15) && set.contains(10) && set.contains(25)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }

    // Test 7: Empty array constructor
    try {
        int* items = nullptr;
        Set<int> set(items, 0);
        std::cout << "Test 7: Empty array constructor - ";
        if (set.isEmpty() && set.size() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }

    // Test 8: Empty ArraySequence constructor
    try {
        ArraySequence<int> arr;
        Set<int> set(arr);
        std::cout << "Test 8: Empty ArraySequence constructor - ";
        if (set.isEmpty() && set.size() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    // Test 9: Array constructor with Person
    try {
        Person people[] = { {"Alice", 25}, {"Bob", 30}, {"Charlie", 35} };
        Set<Person> set(people, 3);
        std::cout << "Test 9: Array constructor with Person - ";
        if (set.size() == 3 && set.contains({ "Alice", 25 }) && set.contains({ "Bob", 30 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }

    // Test 10: Array constructor with Student
    try {
        Student students[] = { {"Alice", 20, "MIT"}, {"Bob", 22, "Stanford"} };
        Set<Student> set(students, 2);
        std::cout << "Test 10: Array constructor with Student - ";
        if (set.size() == 2 && set.contains({ "Alice", 20, "MIT" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }

    // Test 11: Array constructor with strings
    try {
        std::string items[] = { "apple", "banana", "cherry" };
        Set<std::string> set(items, 3);
        std::cout << "Test 11: Array constructor with strings - ";
        if (set.size() == 3 && set.contains("banana") && !set.contains("orange")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
}
void testSetInsert() {
    std::cout << "=== Set Insert Testing ===\n";

    // Test 1: Insert single element
    try {
        Set<int> set;
        set.insert(42);
        std::cout << "Test 1: Insert single element - ";
        if (set.size() == 1 && set.contains(42)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Insert multiple elements
    try {
        Set<std::string> set;
        set.insert("apple")->insert("banana")->insert("orange");
        std::cout << "Test 2: Insert multiple elements - ";
        if (set.size() == 3 && set.contains("banana") && set.contains("orange")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Insert duplicate elements
    try {
        Set<int> set;
        set.insert(10)->insert(10)->insert(10);
        std::cout << "Test 3: Insert duplicate elements - ";
        if (set.size() == 1 && set.contains(10)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    // Test 4: Insert Person objects
    try {
        Set<Person> set;
        set.insert({ "Alice", 25 })->insert({ "Bob", 30 });
        std::cout << "Test 4: Insert Person objects - ";
        if (set.size() == 2 && set.contains({ "Alice", 25 }) && !set.contains({ "Charlie", 35 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Insert Student objects
    try {
        Set<Student> set;
        set.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
        std::cout << "Test 5: Insert Student objects - ";
        if (set.size() == 2 && set.contains({ "Alice", 20, "MIT" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Insert strings with different cases
    try {
        Set<std::string> set;
        set.insert("Apple")->insert("apple");
        std::cout << "Test 6: Insert strings with different cases - ";
        if (set.size() == 2 && set.contains("Apple") && set.contains("apple")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
}
void testSetRemove() {
    std::cout << "=== Set Remove Testing ===\n";

    // Test 1: Remove existing element
    try {
        Set<int> set;
        set.insert(1)->insert(2)->insert(3);
        set.remove(2);
        std::cout << "Test 1: Remove existing element - ";
        if (set.size() == 2 && !set.contains(2) && set.contains(1)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Remove non-existent element
    try {
        Set<int> set;
        set.insert(5);
        set.remove(10);
        std::cout << "Test 2: Remove non-existent element - ";
        if (set.size() == 1 && set.contains(5)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Remove from empty set
    try {
        Set<std::string> set;
        set.remove("test");
        std::cout << "Test 3: Remove from empty set - ";
        if (set.isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    // Test 4: Remove Person object
    try {
        Set<Person> set;
        set.insert({ "Alice", 25 })->insert({ "Bob", 30 });
        set.remove({ "Alice", 25 });
        std::cout << "Test 4: Remove Person object - ";
        if (set.size() == 1 && !set.contains({ "Alice", 25 }) && set.contains({ "Bob", 30 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Remove Student object
    try {
        Set<Student> set;
        set.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
        set.remove({ "Alice", 20, "MIT" });
        std::cout << "Test 5: Remove Student object - ";
        if (set.size() == 1 && !set.contains({ "Alice", 20, "MIT" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Remove string
    try {
        Set<std::string> set;
        set.insert("apple")->insert("banana");
        set.remove("apple");
        std::cout << "Test 6: Remove string - ";
        if (set.size() == 1 && !set.contains("apple") && set.contains("banana")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
}
void testSetContains() {
    std::cout << "=== Set Contains Testing ===\n";

    // Test 1: Contains in non-empty set
    try {
        int m[] = {1, 2, 3, 4, 5};
        Set<int> set(m, 5);
        std::cout << "Test 1: Contains in non-empty set - ";
        if (set.contains(3) && !set.contains(6)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Contains in empty set
    try {
        Set<double> set;
        std::cout << "Test 2: Contains in empty set - ";
        if (!set.contains(3.14)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Contains with custom type
    try {
        
        auto comp = [](const Point& a, const Point& b) {
            return a.x == b.x && a.y == b.y;
            };

        Set<Point> set;
        set.insert(Point{ 1, 2 });
        std::cout << "Test 3: Contains with custom type - ";
        if (set.contains(Point{ 1, 2 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    // Test 4: Contains with Person
    try {
        Set<Person> set;
        set.insert({ "Alice", 25 })->insert({ "Bob", 30 });
        std::cout << "Test 4: Contains with Person - ";
        if (set.contains({ "Alice", 25 }) && !set.contains({ "Charlie", 35 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Contains with Student
    try {
        Set<Student> set;
        set.insert({ "Alice", 20, "MIT" });
        std::cout << "Test 5: Contains with Student - ";
        if (set.contains({ "Alice", 20, "MIT" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Contains with strings
    try {
        Set<std::string> set;
        set.insert("apple")->insert("banana");
        std::cout << "Test 6: Contains with strings - ";
        if (set.contains("banana") && !set.contains("orange")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
}
void testSetUnion() {
    std::cout << "=== Set Union Testing ===\n";

    // Test 1: Union of two non-empty sets with overlapping elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(2)->insert(3)->insert(4);
        Set<int> set2;
        set2.insert(3)->insert(4)->insert(5)->insert(6);
        Set<int>* result = set1.unionWith(set2);
        std::cout << "Test 1: Union of non-empty sets with overlap - ";
        if (result->size() == 6 &&
            result->contains(1) && result->contains(2) &&
            result->contains(3) && result->contains(4) &&
            result->contains(5) && result->contains(6) &&
            !result->contains(7)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Union of non-empty set with empty set
    try {
        Set<int> set1;
        set1.insert(10)->insert(20)->insert(30);
        Set<int> set2;
        Set<int>* result = set1.unionWith(set2);
        std::cout << "Test 2: Union with empty set - ";
        if (result->size() == 3 &&
            result->contains(10) && result->contains(20) &&
            result->contains(30) && !result->contains(40)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Union of two empty sets
    try {
        Set<int> set1;
        Set<int> set2;
        Set<int>* result = set1.unionWith(set2);
        std::cout << "Test 3: Union of two empty sets - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Union of sets with no common elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(3)->insert(5);
        Set<int> set2;
        set2.insert(2)->insert(4)->insert(6);
        Set<int>* result = set1.unionWith(set2);
        std::cout << "Test 4: Union of sets with no common elements - ";
        if (result->size() == 6 &&
            result->contains(1) && result->contains(3) && result->contains(5) &&
            result->contains(2) && result->contains(4) && result->contains(6)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Union with custom Point type
    try {
        Set<Point> set1;
        set1.insert(Point{ 1, 2 })->insert(Point{ 3, 4 });
        Set<Point> set2;
        set2.insert(Point{ 3, 4 })->insert(Point{ 5, 6 });
        Set<Point>* result = set1.unionWith(set2);
        std::cout << "Test 5: Union with custom Point type - ";
        if (result->size() == 3 &&
            result->contains(Point{ 1, 2 }) &&
            result->contains(Point{ 3, 4 }) &&
            result->contains(Point{ 5, 6 }) &&
            !result->contains(Point{ 7, 8 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Union of large sets
    try {
        Set<int> set1;
        Set<int> set2;
        for (int i = 0; i < 100; ++i) {
            set1.insert(i);
            set2.insert(i + 50);
        }
        Set<int>* result = set1.unionWith(set2);
        std::cout << "Test 6: Union of large sets with overlap - ";
        if (result->size() == 150 &&
            result->contains(0) && result->contains(49) &&
            result->contains(50) && result->contains(99) &&
            result->contains(100) && result->contains(149) &&
            !result->contains(150)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    // Test 7: Union with Person sets
    try {
        Set<Person> set1;
        set1.insert({ "Alice", 25 })->insert({ "Bob", 30 });
        Set<Person> set2;
        set2.insert({ "Bob", 30 })->insert({ "Charlie", 35 });
        Set<Person>* result = set1.unionWith(set2);
        std::cout << "Test 7: Union with Person sets - ";
        if (result->size() == 3 &&
            result->contains({ "Alice", 25 }) &&
            result->contains({ "Bob", 30 }) &&
            result->contains({ "Charlie", 35 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }

    // Test 8: Union with Student sets
    try {
        Set<Student> set1;
        set1.insert({ "Alice", 20, "MIT" });
        Set<Student> set2;
        set2.insert({ "Bob", 22, "Stanford" });
        Set<Student>* result = set1.unionWith(set2);
        std::cout << "Test 8: Union with Student sets - ";
        if (result->size() == 2 &&
            result->contains({ "Alice", 20, "MIT" }) &&
            result->contains({ "Bob", 22, "Stanford" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }

    // Test 9: Union with string sets
    try {
        Set<std::string> set1;
        set1.insert("apple")->insert("banana");
        Set<std::string> set2;
        set2.insert("banana")->insert("cherry");
        Set<std::string>* result = set1.unionWith(set2);
        std::cout << "Test 9: Union with string sets - ";
        if (result->size() == 3 &&
            result->contains("apple") &&
            result->contains("banana") &&
            result->contains("cherry")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
}
void testSetIntersection() {
    std::cout << "=== Set Intersection Testing ===\n";

    // Test 1: Intersection of two non-empty sets with overlapping elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(2)->insert(3)->insert(4);
        Set<int> set2;
        set2.insert(3)->insert(4)->insert(5)->insert(6);
        Set<int>* result = set1.intersectionWith(set2);
        std::cout << "Test 1: Intersection of non-empty sets with overlap - ";
        if (result->size() == 2 &&
            result->contains(3) && result->contains(4) &&
            !result->contains(1) && !result->contains(5)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Intersection of non-empty set with empty set
    try {
        Set<int> set1;
        set1.insert(10)->insert(20)->insert(30);
        Set<int> set2;
        Set<int>* result = set1.intersectionWith(set2);
        std::cout << "Test 2: Intersection with empty set - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Intersection of two empty sets
    try {
        Set<int> set1;
        Set<int> set2;
        Set<int>* result = set1.intersectionWith(set2);
        std::cout << "Test 3: Intersection of two empty sets - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Intersection of sets with no common elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(3)->insert(5);
        Set<int> set2;
        set2.insert(2)->insert(4)->insert(6);
        Set<int>* result = set1.intersectionWith(set2);
        std::cout << "Test 4: Intersection of sets with no common elements - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Intersection with custom Point type
    try {
        Set<Point> set1;
        set1.insert(Point{ 1, 2 })->insert(Point{ 3, 4 })->insert(Point{ 7, 8 });
        Set<Point> set2;
        set2.insert(Point{ 3, 4 })->insert(Point{ 5, 6 })->insert(Point{ 7, 8 });
        Set<Point>* result = set1.intersectionWith(set2);
        std::cout << "Test 5: Intersection with custom Point type - ";
        if (result->size() == 2 &&
            result->contains(Point{ 3, 4 }) &&
            result->contains(Point{ 7, 8 }) &&
            !result->contains(Point{ 1, 2 }) &&
            !result->contains(Point{ 5, 6 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Intersection of large sets with partial overlap
    try {
        Set<int> set1;
        Set<int> set2;
        for (int i = 0; i < 100; ++i) {
            set1.insert(i);
            if (i >= 50) {
                set2.insert(i);
            }
        }
        Set<int>* result = set1.intersectionWith(set2);
        std::cout << "Test 6: Intersection of large sets with partial overlap - ";
        if (result->size() == 50 &&
            result->contains(50) && result->contains(75) &&
            result->contains(99) && !result->contains(49) &&
            !result->contains(100)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        Set<Person> set1;
        set1.insert({ "Alice", 25 })->insert({ "Bob", 30 });
        Set<Person> set2;
        set2.insert({ "Bob", 30 })->insert({ "Charlie", 35 });
        Set<Person>* result = set1.intersectionWith(set2);
        std::cout << "Test 7: Intersection with Person sets - ";
        if (result->size() == 1 && result->contains({ "Bob", 30 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }

    // Test 8: Intersection with Student sets
    try {
        Set<Student> set1;
        set1.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
        Set<Student> set2;
        set2.insert({ "Bob", 22, "Stanford" })->insert({ "Charlie", 23, "Harvard" });
        Set<Student>* result = set1.intersectionWith(set2);
        std::cout << "Test 8: Intersection with Student sets - ";
        if (result->size() == 1 && result->contains({ "Bob", 22, "Stanford" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }

    // Test 9: Intersection with string sets
    try {
        Set<std::string> set1;
        set1.insert("apple")->insert("banana")->insert("cherry");
        Set<std::string> set2;
        set2.insert("banana")->insert("cherry")->insert("date");
        Set<std::string>* result = set1.intersectionWith(set2);
        std::cout << "Test 9: Intersection with string sets - ";
        if (result->size() == 2 &&
            result->contains("banana") &&
            result->contains("cherry") &&
            !result->contains("apple")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
}
void testSetDifference() {
    std::cout << "=== Set Difference Testing ===\n";

    // Test 1: Difference of two non-empty sets with overlapping elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(2)->insert(3)->insert(4);
        Set<int> set2;
        set2.insert(3)->insert(4)->insert(5)->insert(6);
        Set<int>* result = set1.differenceWith(set2);
        std::cout << "Test 1: Difference of non-empty sets with overlap - ";
        if (result->size() == 2 &&
            result->contains(1) && result->contains(2) &&
            !result->contains(3) && !result->contains(4) &&
            !result->contains(5)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Difference of non-empty set with empty set
    try {
        Set<int> set1;
        set1.insert(10)->insert(20)->insert(30);
        Set<int> set2;
        Set<int>* result = set1.differenceWith(set2);
        std::cout << "Test 2: Difference with empty set - ";
        if (result->size() == 3 &&
            result->contains(10) && result->contains(20) &&
            result->contains(30) && !result->contains(40)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Difference of empty set with non-empty set
    try {
        Set<int> set1;
        Set<int> set2;
        set2.insert(1)->insert(2)->insert(3);
        Set<int>* result = set1.differenceWith(set2);
        std::cout << "Test 3: Difference of empty set with non-empty set - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Difference of sets with no common elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(3)->insert(5);
        Set<int> set2;
        set2.insert(2)->insert(4)->insert(6);
        Set<int>* result = set1.differenceWith(set2);
        std::cout << "Test 4: Difference of sets with no common elements - ";
        if (result->size() == 3 &&
            result->contains(1) && result->contains(3) &&
            result->contains(5) && !result->contains(2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Difference with custom Point type
    try {
        Set<Point> set1;
        set1.insert(Point{ 1, 2 })->insert(Point{ 3, 4 })->insert(Point{ 7, 8 });
        Set<Point> set2;
        set2.insert(Point{ 3, 4 })->insert(Point{ 5, 6 });
        Set<Point>* result = set1.differenceWith(set2);
        std::cout << "Test 5: Difference with custom Point type - ";
        if (result->size() == 2 &&
            result->contains(Point{ 1, 2 }) &&
            result->contains(Point{ 7, 8 }) &&
            !result->contains(Point{ 3, 4 }) &&
            !result->contains(Point{ 5, 6 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Difference of large sets with partial overlap
    try {
        Set<int> set1;
        Set<int> set2;
        for (int i = 0; i < 100; ++i) {
            set1.insert(i);
            if (i >= 50) {
                set2.insert(i); 
            }
        }
        Set<int>* result = set1.differenceWith(set2);
        std::cout << "Test 6: Difference of large sets with partial overlap - ";
        if (result->size() == 50 &&
            result->contains(0) && result->contains(25) &&
            result->contains(49) && !result->contains(50) &&
            !result->contains(75) && !result->contains(100)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        Set<Person> set1;
        set1.insert({ "Alice", 25 })->insert({ "Bob", 30 })->insert({ "Charlie", 35 });
        Set<Person> set2;
        set2.insert({ "Bob", 30 })->insert({ "David", 40 });
        Set<Person>* result = set1.differenceWith(set2);
        std::cout << "Test 7: Difference with Person sets - ";
        if (result->size() == 2 &&
            result->contains({ "Alice", 25 }) &&
            result->contains({ "Charlie", 35 }) &&
            !result->contains({ "Bob", 30 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }

    // Test 8: Difference with Student sets
    try {
        Set<Student> set1;
        set1.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
        Set<Student> set2;
        set2.insert({ "Bob", 22, "Stanford" });
        Set<Student>* result = set1.differenceWith(set2);
        std::cout << "Test 8: Difference with Student sets - ";
        if (result->size() == 1 && result->contains({ "Alice", 20, "MIT" })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }

    // Test 9: Difference with string sets
    try {
        Set<std::string> set1;
        set1.insert("apple")->insert("banana")->insert("cherry");
        Set<std::string> set2;
        set2.insert("banana")->insert("date");
        Set<std::string>* result = set1.differenceWith(set2);
        std::cout << "Test 9: Difference with string sets - ";
        if (result->size() == 2 &&
            result->contains("apple") &&
            result->contains("cherry") &&
            !result->contains("banana")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
}
void testSetIsSubsetOf() {
    std::cout << "=== Set isSubsetOf Testing ===\n";

    // Test 1: Proper subset
    try {
        Set<int> set1;
        set1.insert(1)->insert(2);
        Set<int> set2;
        set2.insert(1)->insert(2)->insert(3)->insert(4);
        std::cout << "Test 1: Proper subset - ";
        if (set1.isSubsetOf(set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Identical sets
    try {
        Set<int> set1;
        set1.insert(10)->insert(20)->insert(30);
        Set<int> set2;
        set2.insert(10)->insert(20)->insert(30);
        std::cout << "Test 2: Identical sets - ";
        if (set1.isSubsetOf(set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Empty set as subset of non-empty set
    try {
        Set<int> set1;
        Set<int> set2;
        set2.insert(1)->insert(2)->insert(3);
        std::cout << "Test 3: Empty set as subset of non-empty set - ";
        if (set1.isSubsetOf(set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Empty set as subset of empty set
    try {
        Set<int> set1;
        Set<int> set2;
        std::cout << "Test 4: Empty set as subset of empty set - ";
        if (set1.isSubsetOf(set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Non-subset
    try {
        Set<int> set1;
        set1.insert(1)->insert(2)->insert(3);
        Set<int> set2;
        set2.insert(2)->insert(3)->insert(4);
        std::cout << "Test 5: Non-subset - ";
        if (!set1.isSubsetOf(set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Subset with custom Point type
    try {
        Set<Point> set1;
        set1.insert(Point{ 1, 2 })->insert(Point{ 3, 4 });
        Set<Point> set2;
        set2.insert(Point{ 1, 2 })->insert(Point{ 3, 4 })->insert(Point{ 5, 6 });
        std::cout << "Test 6: Subset with custom Point type - ";
        if (set1.isSubsetOf(set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        // Test 7: Subset with Person sets
        try {
            Set<Person> set1;
            set1.insert({ "Alice", 25 })->insert({ "Bob", 30 });
            Set<Person> set2;
            set2.insert({ "Alice", 25 })->insert({ "Bob", 30 })->insert({ "Charlie", 35 });
            std::cout << "Test 7: Subset with Person sets - ";
            if (set1.isSubsetOf(set2)) {
                std::cout << "Passed\n";
            }
            else {
                std::cout << "Failed\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
        }

        // Test 8: Subset with Student sets
        try {
            Set<Student> set1;
            set1.insert({ "Alice", 20, "MIT" });
            Set<Student> set2;
            set2.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
            std::cout << "Test 8: Subset with Student sets - ";
            if (set1.isSubsetOf(set2)) {
                std::cout << "Passed\n";
            }
            else {
                std::cout << "Failed\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
        }

        // Test 9: Subset with string sets
        try {
            Set<std::string> set1;
            set1.insert("banana")->insert("cherry");
            Set<std::string> set2;
            set2.insert("apple")->insert("banana")->insert("cherry")->insert("date");
            std::cout << "Test 9: Subset with string sets - ";
            if (set1.isSubsetOf(set2)) {
                std::cout << "Passed\n";
            }
            else {
                std::cout << "Failed\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
}
void testSetMap() {
    std::cout << "=== Set Map Testing ===\n";

    // Test 1: Map non-empty set of integers with multiplication
    try {
        Set<int> set;
        set.insert(1)->insert(2)->insert(3);
        std::function<int(const int&)> multiply = [](const int& x) -> int { return x * 2; };
        Set<int>* result = set.map(multiply);
        std::cout << "Test 1: Map non-empty set of integers (multiply by 2) - ";
        if (result->size() == 3 &&
            result->contains(2) && result->contains(4) &&
            result->contains(6) && !result->contains(1)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Map empty set of integers
    try {
        Set<int> set;
        std::function<int(const int&)> multiply = [](const int& x) -> int { return x * 2; };
        Set<int>* result = set.map(multiply);
        std::cout << "Test 2: Map empty set of integers - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Map integers to strings
    try {
        Set<int> set;
        set.insert(1)->insert(2)->insert(3);
        std::function<std::string(const int&)> to_string = [](const int& x) -> std::string { return std::to_string(x); };
        Set<std::string>* result = set.map(to_string);
        std::cout << "Test 3: Map integers to strings - ";
        if (result->size() == 3 &&
            result->contains("1") && result->contains("2") &&
            result->contains("3") && !result->contains("4")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Map Point objects to their x-coordinates
    try {
        Set<Point> set;
        set.insert(Point{ 1, 2 })->insert(Point{ 3, 4 })->insert(Point{ 5, 6 });
        std::function<int(const Point&)> get_x = [](const Point& p) -> int { return p.x; };
        Set<int>* result = set.map(get_x);
        std::cout << "Test 4: Map Point objects to x-coordinates - ";
        if (result->size() == 3 &&
            result->contains(1) && result->contains(3) &&
            result->contains(5) && !result->contains(2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Map Point objects to strings
    try {
        Set<Point> set;
        set.insert(Point{ 1, 2 })->insert(Point{ 3, 4 });
        std::function<std::string(const Point&)> to_string = [](const Point& p) -> std::string {
            return "(" + std::to_string(p.x) + "," + std::to_string(p.y) + ")";
            };
        Set<std::string>* result = set.map(to_string);
        std::cout << "Test 5: Map Point objects to strings - ";
        if (result->size() == 2 &&
            result->contains("(1,2)") && result->contains("(3,4)") &&
            !result->contains("(5,6)")) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Map large set of integers
    try {
        Set<int> set;
        for (int i = 1; i <= 100; ++i) {
            set.insert(i);
        }
        std::function<int(const int&)> square = [](const int& x) -> int { return x * x; };
        Set<int>* result = set.map(square);
        std::cout << "Test 6: Map large set of integers (square) - ";
        if (result->size() == 100 &&
            result->contains(1) && result->contains(4) &&
            result->contains(100) && result->contains(10000) &&
            !result->contains(0)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
}
void testSetWhere() {
    std::cout << "=== Set Where Testing ===\n";

    // Test 1: Filter non-empty set of integers to keep even numbers
    try {
        Set<int> set;
        set.insert(1)->insert(2)->insert(3)->insert(4);
        std::function<bool(const int&)> is_even = [](const int& x) -> bool { return x % 2 == 0; };
        Set<int>* result = set.where(is_even);
        std::cout << "Test 1: Filter non-empty set to keep even numbers - ";
        if (result->size() == 2 &&
            result->contains(2) && result->contains(4) &&
            !result->contains(1) && !result->contains(3)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Filter empty set of integers
    try {
        Set<int> set;
        std::function<bool(const int&)> is_even = [](const int& x) -> bool { return x % 2 == 0; };
        Set<int>* result = set.where(is_even);
        std::cout << "Test 2: Filter empty set of integers - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Filter non-empty set to keep no elements
    try {
        Set<int> set;
        set.insert(1)->insert(2)->insert(3);
        std::function<bool(const int&)> always_false = [](const int& x) -> bool { return false; };
        Set<int>* result = set.where(always_false);
        std::cout << "Test 3: Filter non-empty set to keep no elements - ";
        if (result->isEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Filter Point objects to keep points where x == y
    try {
        Set<Point> set;
        set.insert(Point{ 1, 1 })->insert(Point{ 2, 3 })->insert(Point{ 3, 3 });
        std::function<bool(const Point&)> x_equals_y = [](const Point& p) -> bool { return p.x == p.y; };
        Set<Point>* result = set.where(x_equals_y);
        std::cout << "Test 4: Filter Point objects to keep x == y - ";
        if (result->size() == 2 &&
            result->contains(Point{ 1, 1 }) && result->contains(Point{ 3, 3 }) &&
            !result->contains(Point{ 2, 3 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Filter Point objects to keep points where x > y
    try {
        Set<Point> set;
        set.insert(Point{ 2, 1 })->insert(Point{ 1, 2 })->insert(Point{ 3, 2 });
        std::function<bool(const Point&)> x_greater_y = [](const Point& p) -> bool { return p.x > p.y; };
        Set<Point>* result = set.where(x_greater_y);
        std::cout << "Test 5: Filter Point objects to keep x > y - ";
        if (result->size() == 2 &&
            result->contains(Point{ 2, 1 }) && result->contains(Point{ 3, 2 }) &&
            !result->contains(Point{ 1, 2 })) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Filter large set of integers to keep numbers divisible by 3
    try {
        Set<int> set;
        for (int i = 1; i <= 100; ++i) {
            set.insert(i);
        }
        std::function<bool(const int&)> divisible_by_3 = [](const int& x) -> bool { return x % 3 == 0; };
        Set<int>* result = set.where(divisible_by_3);
        std::cout << "Test 6: Filter large set to keep numbers divisible by 3 - ";
        if (result->size() == 33 &&
            result->contains(3) && result->contains(6) &&
            result->contains(99) && !result->contains(1) &&
            !result->contains(100)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
}
void testSetEqual() {
    std::cout << "=== Set Equality Testing ===\n";

    // Test 1: Compare two identical non-empty sets of integers
    try {
        Set<int> set1;
        set1.insert(1)->insert(2)->insert(3);
        Set<int> set2;
        set2.insert(1)->insert(2)->insert(3);
        std::cout << "Test 1: Compare identical non-empty sets of integers - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Compare two empty sets
    try {
        Set<int> set1;
        Set<int> set2;
        std::cout << "Test 2: Compare two empty sets - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Compare non-empty sets with different elements
    try {
        Set<int> set1;
        set1.insert(1)->insert(2)->insert(3);
        Set<int> set2;
        set2.insert(2)->insert(3)->insert(4);
        std::cout << "Test 3: Compare non-empty sets with different elements - ";
        if (!(set1 == set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Compare non-empty set with empty set
    try {
        Set<int> set1;
        set1.insert(1)->insert(2);
        Set<int> set2;
        std::cout << "Test 4: Compare non-empty set with empty set - ";
        if (!(set1 == set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Compare identical sets of Point objects
    try {
        Set<Point> set1;
        set1.insert(Point{ 1, 2 })->insert(Point{ 3, 4 });
        Set<Point> set2;
        set2.insert(Point{ 1, 2 })->insert(Point{ 3, 4 });
        std::cout << "Test 5: Compare identical sets of Point objects - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Compare large sets with one different element
    try {
        Set<int> set1;
        Set<int> set2;
        for (int i = 1; i <= 100; ++i) {
            set1.insert(i);
            if (i != 100) {
                set2.insert(i);
            }
            else {
                set2.insert(101);
            }
        }
        std::cout << "Test 6: Compare large sets with one different element - ";
        if (!(set1 == set2)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }

    // Test 7: Compare sets with same elements but different insertion order
    try {
        Set<int> set1;
        set1.insert(2)->insert(1)->insert(3);
        Set<int> set2;
        set2.insert(1)->insert(2)->insert(3);
        std::cout << "Test 7: Compare sets with same elements but different insertion order - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    // Test 8: Equality with Person sets
    try {
        Set<Person> set1;
        set1.insert({ "Alice", 25 })->insert({ "Bob", 30 });
        Set<Person> set2;
        set2.insert({ "Bob", 30 })->insert({ "Alice", 25 });
        std::cout << "Test 8: Equality with Person sets - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }

    // Test 9: Equality with Student sets
    try {
        Set<Student> set1;
        set1.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
        Set<Student> set2;
        set2.insert({ "Alice", 20, "MIT" })->insert({ "Bob", 22, "Stanford" });
        std::cout << "Test 9: Equality with Student sets - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }

    // Test 10: Equality with string sets
    try {
        Set<std::string> set1;
        set1.insert("apple")->insert("banana");
        Set<std::string> set2;
        set2.insert("banana")->insert("apple");
        std::cout << "Test 10: Equality with string sets - ";
        if (set1 == set2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
}






void testSet() {
    std::cout << "=== Testing Set ===\n";
    testSetConstructors();
    testSetInsert();
    testSetRemove();
    testSetContains();
    testSetUnion();
    testSetIntersection();
    testSetDifference();
    testSetIsSubsetOf();
    testSetMap();
    testSetWhere();
    testSetEqual();
}
