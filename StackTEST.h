#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <functional>
#include "Stack.h"
#include "SetTEST.h"
#include "ArraySequence.h"
void testStackConstructors() {
    std::cout << "=== Stack Constructors Testing ===\n";

    // Test 1: Default constructor
    try {
        Stack<int> s;
        std::cout << "Test 1: Default constructor - ";
        if (s.IsEmpty() && s.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Constructor from array
    try {
        int data[] = { 10, 20, 30 };
        Stack<int> s(data, 3);
        std::cout << "Test 2: Constructor from array - ";
        if (s.GetLength() == 3 && s.Top() == 30) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Copy constructor
    try {
        Stack<int> original;
        original.Push(42);
        Stack<int> copy(original);
        std::cout << "Test 3: Copy constructor - ";
        if (copy.GetLength() == 1 && copy.Top() == 42) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Constructor from ListSequence
    try {
        int items[] = { 1, 2, 3 };
        ListSequence<int> list(items, 3);
        Stack<int> s(list);
        std::cout << "Test 4: Constructor from ListSequence - ";
        if (s.GetLength() == 3 && s.Top() == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Constructor with `Person`
    try {
        Person people[] = { {"Alice", 25}, {"Bob", 30} };
        Stack<Person> s(people, 2);
        std::cout << "Test 5: Constructor with Person - ";
        if (s.GetLength() == 2 && s.Top() == Person("Bob", 30)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Constructor with `Student`
    try {
        Student students[] = { {"Ann", 20, "MIT"}, {"Rob", 22, "Cambridge"} };
        Stack<Student> s(students, 2);
        std::cout << "Test 6: Constructor with Student - ";
        if (s.GetLength() == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }

    // Test 7: Constructor with strings
    try {
        std::string data[] = { "first", "second", "third" };
        Stack<std::string> s(data, 3);
        std::cout << "Test 7: Constructor with strings - ";
        if (s.GetLength() == 3 && s.Top() == "third") {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
}
void testStackPush() {
    std::cout << "=== Stack Push Testing ===\n";

    // Test 1: Push integers
    try {
        Stack<int> s;
        s.Push(10);
        s.Push(20);
        s.Push(30);
        std::cout << "Test 1: Push integers - ";
        if (s.GetLength() == 3 && s.Top() == 30) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Push strings
    try {
        Stack<std::string> s;
        s.Push("alpha");
        s.Push("beta");
        std::cout << "Test 2: Push strings - ";
        if (s.GetLength() == 2 && s.Top() == "beta") {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Push Person objects
    try {
        Stack<Person> s;
        s.Push(Person("Alice", 25));
        s.Push(Person("Bob", 30));
        std::cout << "Test 3: Push Person objects - ";
        if (s.GetLength() == 2 && s.Top() == Person("Bob", 30)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Push Student objects
    try {
        Stack<Student> s;
        s.Push(Student("Ann", 20, "MIT"));
        s.Push(Student("Rob", 22, "Stanford"));
        std::cout << "Test 4: Push Student objects - ";
        if (s.GetLength() == 2) {
            std::cout << "Passed\n"; 
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
}
void testStackPop() {
    std::cout << "=== Stack Pop Testing ===\n";

    // Test 1: Pop from stack of integers
    try {
        Stack<int> s;
        s.Push(100);
        s.Push(200);
        s.Push(300);
        s.Pop();
        std::cout << "Test 1: Pop from integer stack - ";
        if (s.GetLength() == 2 && s.Top() == 200) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Pop from stack with single string
    try {
        Stack<std::string> s;
        s.Push("only");
        s.Pop();
        std::cout << "Test 2: Pop single string - ";
        if (s.IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Pop from empty stack (should throw)
    try {
        Stack<int> s;
        s.Pop();
        std::cout << "Test 3: Pop from empty stack - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 3: Pop from empty stack - Passed (caught exception)\n";
    }
    catch (...) {
        std::cout << "Test 3: Pop from empty stack - Failed (wrong exception type)\n";
    }

    // Test 4: Pop Person objects
    try {
        Stack<Person> s;
        s.Push(Person("Alice", 25));
        s.Push(Person("Bob", 30));
        s.Pop();
        std::cout << "Test 4: Pop Person - ";
        if (s.GetLength() == 1 && s.Top() == Person("Alice", 25)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Pop Student objects
    try {
        Stack<Student> s;
        s.Push(Student("Ann", 20, "MIT"));
        s.Push(Student("Rob", 22, "Stanford"));
        s.Pop();
        std::cout << "Test 5: Pop Student - ";
        if (s.GetLength() == 1) {
            std::cout << "Passed\n"; 
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }
}
void testStackTop() {
    std::cout << "=== Stack Top Testing ===\n";

    // Test 1: Top after multiple pushes (integers)
    try {
        Stack<int> s;
        s.Push(5);
        s.Push(15);
        s.Push(25);
        std::cout << "Test 1: Top after pushes - ";
        if (s.Top() == 25) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Top with strings
    try {
        Stack<std::string> s;
        s.Push("first");
        s.Push("second");
        std::cout << "Test 2: Top with strings - ";
        if (s.Top() == "second") {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Top with Person
    try {
        Stack<Person> s;
        s.Push(Person("Alice", 28));
        s.Push(Person("Bob", 34));
        std::cout << "Test 3: Top with Person - ";
        if (s.Top() == Person("Bob", 34)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Top with Student
    try {
        Stack<Student> s;
        s.Push(Student("Ann", 20, "MIT"));
        s.Push(Student("Eve", 21, "Harvard"));
        std::cout << "Test 4: Top with Student - ";
        if (s.GetLength() == 2) { 
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Top on empty stack (should throw)
    try {
        Stack<int> s;
        s.Top();
        std::cout << "Test 5: Top on empty stack - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: Top on empty stack - Passed (caught exception)\n";
    }
    catch (...) {
        std::cout << "Test 5: Top on empty stack - Failed (wrong exception type)\n";
    }
}
void testStackIsEmpty() {
    std::cout << "=== Stack IsEmpty Testing ===\n";

    // Test 1: New empty stack
    try {
        Stack<int> s;
        std::cout << "Test 1: New empty stack - ";
        if (s.IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: After one push
    try {
        Stack<std::string> s;
        s.Push("test");
        std::cout << "Test 2: After one push - ";
        if (!s.IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: After push and pop
    try {
        Stack<Person> s;
        s.Push(Person("Alice", 30));
        s.Pop();
        std::cout << "Test 3: After push and pop - ";
        if (s.IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Multiple pushes then check
    try {
        Stack<Student> s;
        s.Push(Student("Ann", 20, "MIT"));
        s.Push(Student("Bob", 21, "Oxford"));
        std::cout << "Test 4: Multiple pushes - ";
        if (!s.IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
}
void testStackConcat() {
    std::cout << "=== Stack Concat Testing ===\n";

    // Test 1: Concat two non-empty integer stacks
    try {
        Stack<int> s1;
        s1.Push(1);
        s1.Push(2);

        Stack<int> s2;
        s2.Push(3);
        s2.Push(4);

        Stack<int>* result = s1.Concat(s2);
        std::cout << "Test 1: Concat two non-empty integer stacks - ";
        if (result->GetLength() == 4 &&
            result->Get(0) == 1 &&
            result->Get(1) == 2 &&
            result->Get(2) == 3 &&
            result->Get(3) == 4) {
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

    // Test 2: Concat with empty stack
    try {
        Stack<std::string> s1;
        s1.Push("hello");

        Stack<std::string> s2;

        Stack<std::string>* result = s1.Concat(s2);
        std::cout << "Test 2: Concat with empty stack - ";
        if (result->GetLength() == 1 && result->Top() == "hello") {
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

    // Test 3: Concat two empty stacks
    try {
        Stack<int> s1;
        Stack<int> s2;
        Stack<int>* result = s1.Concat(s2);
        std::cout << "Test 3: Concat two empty stacks - ";
        if (result->IsEmpty()) {
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

    // Test 4: Concat with Person
    try {
        Stack<Person> s1;
        s1.Push(Person("Alice", 25));
        Stack<Person> s2;
        s2.Push(Person("Bob", 30));

        Stack<Person>* result = s1.Concat(s2);
        std::cout << "Test 4: Concat with Person - ";
        if (result->GetLength() == 2 &&
            result->Get(0) == Person("Alice", 25) &&
            result->Get(1) == Person("Bob", 30)) {
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

    // Test 5: Concat with Student
    try {
        Stack<Student> s1;
        s1.Push(Student("Ann", 20, "MIT"));
        Stack<Student> s2;
        s2.Push(Student("Bob", 22, "Stanford"));

        Stack<Student>* result = s1.Concat(s2);
        std::cout << "Test 5: Concat with Student - ";
        if (result->GetLength() == 2&&result->Get(0)==s1.Get(0)&&result->Get(1)==s2.Get(0)) {
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
}

bool isEven(int x) {
    return x % 2 == 0;
}
bool greaterThanTen(int x) {
    return x > 10;
}
bool alwaysFalse(int) {
    return false;
}
void testStackWhere() {
    std::cout << "=== Stack Where Testing ===\n";

    // Test 1: Filter even numbers
    try {
        Stack<int> s;
        for (int i = 1; i <= 5; ++i) s.Push(i);
        Stack<int>* filtered = s.Where(isEven);
        std::cout << "Test 1: Filter even numbers - ";
        if (filtered->GetLength() == 2 &&
            filtered->Get(0) == 2 &&
            filtered->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete filtered;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Filter numbers > 10
    try {
        Stack<int> s;
        s.Push(5);
        s.Push(15);
        s.Push(25);
        Stack<int>* filtered = s.Where(greaterThanTen);
        std::cout << "Test 2: Filter > 10 - ";
        if (filtered->GetLength() == 2 &&
            filtered->Get(0) == 15 &&
            filtered->Get(1) == 25) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete filtered;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Filter to nothing
    try {
        Stack<int> s;
        s.Push(1);
        s.Push(3);
        Stack<int>* filtered = s.Where(alwaysFalse);
        std::cout << "Test 3: Filter to nothing - ";
        if (filtered->IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete filtered;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Where on empty stack
    try {
        Stack<int> s;
        Stack<int>* filtered = s.Where(isEven);
        std::cout << "Test 4: Where on empty stack - ";
        if (filtered->IsEmpty()) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete filtered;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
}

void testStackMap() {
    std::cout << "=== Stack Map Testing ===\n";

    // Test 1: Simple linear transformation (x -> x*2)
    try {
        int data[] = { 1, 2, 3, 4, 5 };
        Stack<int> s(data, 5);
        auto doubleFunc = [](int x) { return x * 2; };
        Stack<int>* mapped = s.Map<int>(doubleFunc);

        std::cout << "Test 1: Linear transformation (x2) - ";
        bool passed = mapped->GetLength() == 5;
        for (int i = 0; i < 5; ++i) {
            if (mapped->Get(i) != data[i] * 2) {
                passed = false;
                break;
            }
        }
        std::cout << (passed ? "Passed\n" : "Failed\n");
        delete mapped;
    }
    catch (...) {
        std::cout << "Test 1: Failed with unexpected exception\n";
    }

    // Test 2: Complex non-linear transformation (x -> x^2 + 3x - 2)
    try {
        int data[] = { 0, 1, -1, 5, -3 };
        Stack<int> s(data, 5);
        auto complexFunc = [](int x) { return x * x + 3 * x - 2; };
        Stack<int>* mapped = s.Map<int>(complexFunc);

        std::cout << "Test 2: Non-linear transformation - ";
        bool passed = mapped->GetLength() == 5;
        int expected[] = { -2, 2, -4, 38, -2 };
        for (int i = 0; i < 5; ++i) {
            if (mapped->Get(i) != expected[i]) {
                passed = false;
                break;
            }
        }
        std::cout << (passed ? "Passed\n" : "Failed\n");
        delete mapped;
    }
    catch (...) {
        std::cout << "Test 2: Failed with unexpected exception\n";
    }

    // Test 3: Empty stack mapping
    try {
        Stack<int> s;
        auto identityFunc = [](int x) { return x; };
        Stack<int>* mapped = s.Map<int>(identityFunc);

        std::cout << "Test 3: Empty stack mapping - ";
        std::cout << (mapped->IsEmpty() ? "Passed\n" : "Failed\n");
        delete mapped;
    }
    catch (...) {
        std::cout << "Test 3: Failed with unexpected exception\n";
    }

    // Test 4: Mapping with state capture (x -> x + captured_value)
    try {
        int data[] = { 10, 20, 30 };
        Stack<int> s(data, 3);
        auto captureFunc = [](int x) { return x + 5; };
        Stack<int>* mapped = s.Map<int>(captureFunc);

        std::cout << "Test 4: State capture in lambda - ";
        bool passed = mapped->GetLength() == 3;
        for (int i = 0; i < 3; ++i) {
            if (mapped->Get(i) != data[i] + 5) {
                passed = false;
                break;
            }
        }
        std::cout << (passed ? "Passed\n" : "Failed\n");
        delete mapped;
    }
    catch (...) {
        std::cout << "Test 4: Failed with unexpected exception\n";
    }

    // Test 5: Chained mappings (map twice)
    try {
        int data[] = { 1, 2, 3 };
        Stack<int> s(data, 3);
        auto incFunc = [](int x) { return x + 1; };
        auto squareFunc = [](int x) { return x * x; };

        Stack<int>* firstMap = s.Map<int>(incFunc);
        Stack<int>* secondMap = firstMap->Map<int>(squareFunc);

        std::cout << "Test 5: Chained mappings - ";
        bool passed = secondMap->GetLength() == 3;
        int expected[] = { 4, 9, 16 };
        for (int i = 0; i < 3; ++i) {
            if (secondMap->Get(i) != expected[i]) {
                passed = false;
                break;
            }
        }
        std::cout << (passed ? "Passed\n" : "Failed\n");

        delete firstMap;
        delete secondMap;
    }
    catch (...) {
        std::cout << "Test 5: Failed with unexpected exception\n";
    }

    // Test 6: Large stack mapping (1000 elements)
    try {
        const int size = 1000;
        int* data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }

        Stack<int> s(data, size);
        auto modFunc = [](int x) { return (x % 17) * 2; };
        Stack<int>* mapped = s.Map<int>(modFunc);

        std::cout << "Test 6: Large stack mapping - ";
        bool passed = mapped->GetLength() == size;
        for (int i = 0; i < size && passed; ++i) {
            if (mapped->Get(i) != (i % 17) * 2) {
                passed = false;
            }
        }
        std::cout << (passed ? "Passed\n" : "Failed\n");

        delete[] data;
        delete mapped;
    }
    catch (...) {
        std::cout << "Test 6: Failed with unexpected exception\n";
    }

    // Test 7: Edge case with INT_MAX and INT_MIN
    try {
        int data[] = { INT_MAX, INT_MIN, 0 };
        Stack<int> s(data, 3);
        auto overflowFunc = [](int x) { return x + 1; };
        Stack<int>* mapped = s.Map<int>(overflowFunc);

        std::cout << "Test 7: Integer overflow handling - ";
        bool passed = mapped->GetLength() == 3;
        if (passed) {
            passed = (mapped->Get(0) == INT_MIN) && 
                (mapped->Get(1) == INT_MIN + 1) &&
                (mapped->Get(2) == 1);
        }
        std::cout << (passed ? "Passed\n" : "Failed\n");
        delete mapped;
    }
    catch (...) {
        std::cout << "Test 7: Failed with unexpected exception\n";
    }
}
void testStackReduce() {
    std::cout << "=== Stack Reduce Testing ===\n";

    // Test 1: Sum of elements with zero initial value
    try {
        int data[] = { 1, 2, 3, 4, 5 };
        Stack<int> s(data, 5);
        auto sumFunc = [](int a, int b) { return a + b; };
        int result = s.Reduce(sumFunc, 0);

        std::cout << "Test 1: Sum with zero initial - ";
        std::cout << (result == 15 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 1: Failed with unexpected exception\n";
    }

    // Test 2: Product of elements with initial 1
    try {
        int data[] = { 1, 2, 3, 4 };
        Stack<int> s(data, 4);
        auto productFunc = [](int a, int b) { return a * b; };
        int result = s.Reduce(productFunc, 1);

        std::cout << "Test 2: Product with initial 1 - ";
        std::cout << (result == 24 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 2: Failed with unexpected exception\n";
    }

    // Test 3: Empty stack with initial value
    try {
        Stack<int> s;
        auto sumFunc = [](int a, int b) { return a + b; };
        int result = s.Reduce(sumFunc, 42);

        std::cout << "Test 3: Empty stack with initial - ";
        std::cout << (result == 42 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 3: Failed with unexpected exception\n";
    }

    // Test 4: Single element stack
    try {
        int data[] = { 7 };
        Stack<int> s(data, 1);
        auto func = [](int a, int b) { return a + b * 2; };
        int result = s.Reduce(func, 0);

        std::cout << "Test 4: Single element stack - ";
        std::cout << (result == 7 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 4: Failed with unexpected exception\n";
    }

    // Test 5: Find maximum element
    try {
        int data[] = { 3, 1, 4, 1, 5, 9, 2 };
        Stack<int> s(data, 7);
        auto maxFunc = [](int a, int b) { return a > b ? a : b; };
        int result = s.Reduce(maxFunc, INT_MIN);

        std::cout << "Test 5: Find maximum - ";
        std::cout << (result == 9 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 5: Failed with unexpected exception\n";
    }

    // Test 6: Find minimum element
    try {
        int data[] = { 5, 3, 8, 1, -2, 7 };
        Stack<int> s(data, 6);
        auto minFunc = [](int a, int b) { return a < b ? a : b; };
        int result = s.Reduce(minFunc, INT_MAX);

        std::cout << "Test 6: Find minimum - ";
        std::cout << (result == -2 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 6: Failed with unexpected exception\n";
    }

    // Test 7: String concatenation simulation (using int digits)
    try {
        int data[] = { 1, 2, 3, 4 };
        Stack<int> s(data, 4);
        auto concatFunc = [](int a, int b) { return a * 10 + b; };
        int result = s.Reduce(concatFunc, 0);

        std::cout << "Test 7: Digit concatenation - ";
        std::cout << (result == 100 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 7: Failed with unexpected exception\n";
    }

    // Test 8: Large stack (1000 elements)
    try {
        const int size = 1000;
        int* data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 1;
        }

        Stack<int> s(data, size);
        auto sumFunc = [](int a, int b) { return a + b; };
        int result = s.Reduce(sumFunc, 0);

        std::cout << "Test 8: Large stack sum - ";
        std::cout << (result == size ? "Passed\n" : "Failed\n");

        delete[] data;
    }
    catch (...) {
        std::cout << "Test 8: Failed with unexpected exception\n";
    }

    // Test 9: Integer overflow case
    try {
        int data[] = { INT_MAX, 1 };
        Stack<int> s(data, 2);
        auto sumFunc = [](int a, int b) { return a + b; };
        int result = s.Reduce(sumFunc, 0);

        std::cout << "Test 9: Integer overflow - ";
        std::cout << (result == INT_MIN ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 9: Failed with unexpected exception\n";
    }

    // Test 10: Complex reduction with state
    try {
        int data[] = { 1, 2, 3, 4, 5 };
        Stack<int> s(data, 5);
        auto complexFunc = [](int a, int b) { return (a + b) * 2; };
        int result = s.Reduce(complexFunc, 0);
        std::cout << s.Reduce(complexFunc, 0);
        std::cout << "Test 10: Complex reduction - ";
        std::cout << (result == 114 ? "Passed\n" : "Failed\n");
    }
    catch (...) {
        std::cout << "Test 10: Failed with unexpected exception\n";
    }
}


void testStack() {
    testStackConstructors();
    testStackPush();
    testStackPop();
    testStackTop();
    testStackIsEmpty();
    testStackConcat();
    testStackWhere();
    testStackMap();
    testStackReduce();
}




