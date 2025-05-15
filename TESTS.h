#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ImmutableArraySequence.h"
#include "MutableArraySequence.h"
#include "ImmutableListSequence.h"
#include "MutableListSequence.h"
#include "AdaptiveSequence.h"
#include "SegmentedList.h"

void testDynamicArray() {
    std::cout << "=== Testing DynamicArray ===\n";
    try {
        DynamicArray<int> arr;
        std::cout << "Test 1: Default constructor - ";
        if (arr.GetLength() == 0 && arr.GetCapacity() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(3);
        std::cout << "Test 2: Constructor with size 3 - ";
        if (arr.GetLength() == 3 && arr.GetCapacity() == 3 &&
            arr.Get(0) == 0 && arr.Get(1) == 0 && arr.Get(2) == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        DynamicArray<int> arr(items, 3);
        std::cout << "Test 3: Constructor with array [1, 2, 3] - ";
        if (arr.GetLength() == 3 && arr.Get(0) == 1 && arr.Get(1) == 2 && arr.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr1(2);
        arr1.Set(10, 0);
        arr1.Set(20, 1);
        DynamicArray<int> arr2(arr1);
        std::cout << "Test 4: Copy constructor - ";
        if (arr2.GetLength() == 2 && arr2.Get(0) == 10 && arr2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr1(2);
        arr1.Set(5, 0);
        arr1.Set(15, 1);
        DynamicArray<int> arr2;
        arr2 = arr1;
        std::cout << "Test 5: Assignment operator - ";
        if (arr2.GetLength() == 2 && arr2.Get(0) == 5 && arr2.Get(1) == 15) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(2);
        arr.Get(2);
        std::cout << "Test 6: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 6: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(2);
        arr.Set(10, 3);
        std::cout << "Test 7: Set with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 7: Set with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr;
        arr.Append(1);
        arr.Append(2);
        std::cout << "Test 8: Append - ";
        if (arr.GetLength() == 2 && arr.Get(0) == 1 && arr.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr;
        arr.Prepend(2);
        arr.Prepend(1);
        std::cout << "Test 9: Prepend - ";
        if (arr.GetLength() == 2 && arr.Get(0) == 1 && arr.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(2);
        arr.Set(1, 0);
        arr.Set(3, 1);
        arr.InsertAt(2, 1);
        std::cout << "Test 10: InsertAt - ";
        if (arr.GetLength() == 3 && arr.Get(0) == 1 && arr.Get(1) == 2 && arr.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(2);
        arr.Set(1, 0);
        arr.Set(2, 1);
        arr.Resize(4);
        std::cout << "Test 11: Resize to larger size - ";
        if (arr.GetLength() == 2 && arr.GetCapacity() == 4 && arr.Get(0) == 1 && arr.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(3);
        arr.Set(1, 0);
        arr.Set(2, 1);
        arr.Set(3, 2);
        arr.Resize(1);
        std::cout << "Test 12: Resize to smaller size - ";
        if (arr.GetLength() == 1 && arr.GetCapacity() == 1 && arr.Get(0) == 1) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(3);
        arr.Set(1, 0);
        arr.Set(2, 1);
        arr.Set(3, 2);
        DynamicArray<int>* sub = arr.GetSubArray(1, 2);
        std::cout << "Test 13: GetSubArray - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr1(2);
        arr1.Set(1, 0);
        arr1.Set(2, 1);
        DynamicArray<int> arr2(2);
        arr2.Set(3, 0);
        arr2.Set(4, 1);
        DynamicArray<int> result = arr1.Concat(arr2);
        std::cout << "Test 14: Concat - ";
        if (result.GetLength() == 4 && result.Get(0) == 1 && result.Get(1) == 2 &&
            result.Get(2) == 3 && result.Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(2);
        arr.Set(5, 0);
        arr.Set(10, 1);
        std::cout << "Test 15: To_String - ";
        std::cout << "Output: ";
        arr.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(2);
        arr[0] = 7;
        arr[1] = 8;
        std::cout << "Test 16: Operator [] - ";
        if (arr[0] == 7 && arr[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr;
        arr.To_String();
        std::cout << "Test 17: Empty array To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        DynamicArray<int> arr(-1);
        std::cout << "Test 18: Constructor with negative size - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 18: Constructor with negative size - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testLinkedList() {
    std::cout << "=== Testing LinkedList ===\n";
    try {
        LinkedList<int> list;
        std::cout << "Test 1: Default constructor - ";
        if (list.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        LinkedList<int> list(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (list.GetLength() == 3 && list.Get(0) == 1 && list.Get(1) == 2 && list.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list(2);
        std::cout << "Test 3: Constructor with size 2 - ";
        if (list.GetLength() == 2 && list.Get(0) == 0 && list.Get(1) == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list1;
        list1.Append(10);
        list1.Append(20);
        LinkedList<int> list2(list1);
        std::cout << "Test 4: Copy constructor - ";
        if (list2.GetLength() == 2 && list2.Get(0) == 10 && list2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list1;
        list1.Append(5);
        list1.Append(15);
        LinkedList<int> list2;
        list2 = list1;
        std::cout << "Test 5: Assignment operator - ";
        if (list2.GetLength() == 2 && list2.Get(0) == 5 && list2.Get(1) == 15) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(1);
        list.Get(1);
        std::cout << "Test 6: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 6: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.GetFirst();
        std::cout << "Test 7: GetFirst on empty list - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 7: GetFirst on empty list - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(1);
        list.Append(2);
        std::cout << "Test 8: Append - ";
        if (list.GetLength() == 2 && list.Get(0) == 1 && list.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Prepend(2);
        list.Prepend(1);
        std::cout << "Test 9: Prepend - ";
        if (list.GetLength() == 2 && list.Get(0) == 1 && list.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(1);
        list.Append(3);
        list.InsertAt(2, 1);
        std::cout << "Test 10: InsertAt - ";
        if (list.GetLength() == 3 && list.Get(0) == 1 && list.Get(1) == 2 && list.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(1);
        list.Append(2);
        list.Set(10, 1);
        std::cout << "Test 11: Set - ";
        if (list.GetLength() == 2 && list.Get(0) == 1 && list.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(1);
        list.Append(2);
        list.Append(3);
        LinkedList<int>* sub = list.GetSubList(1, 2);
        std::cout << "Test 12: GetSubList - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list1;
        list1.Append(1);
        list1.Append(2);
        LinkedList<int> list2;
        list2.Append(3);
        list2.Append(4);
        LinkedList<int>* result = list1.Concat(list2);
        std::cout << "Test 13: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(5);
        list.Append(10);
        std::cout << "Test 14: To_String - ";
        std::cout << "Output: ";
        list.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.Append(7);
        list.Append(8);
        list[0] = 9;
        std::cout << "Test 15: Operator [] - ";
        if (list[0] == 9 && list[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.To_String();
        std::cout << "Test 16: Empty list To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        LinkedList<int> list;
        list.InsertAt(1, 2);
        std::cout << "Test 17: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 17: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testListSequence() {
    std::cout << "=== Testing ListSequence ===\n";
    try {
        ListSequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ListSequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq(2);
        std::cout << "Test 3: Constructor with size 2 - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 0 && seq.Get(1) == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq1;
        seq1.Append(10);
        seq1.Append(20);
        ListSequence<int> seq2(seq1);
        std::cout << "Test 4: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1);
        seq.Get(1);
        std::cout << "Test 5: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 6: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 6: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(2);
        std::cout << "Test 7: Append - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Prepend(2)->Prepend(1);
        std::cout << "Test 8: Prepend - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(3);
        seq.InsertAt(2, 1);
        std::cout << "Test 9: InsertAt - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(2);
        seq.Set(10, 1);
        std::cout << "Test 10: Set - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 11: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq1;
        seq1.Append(1)->Append(2);
        ListSequence<int> seq2;
        seq2.Append(3)->Append(4);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 12: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 13: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3)->Append(4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 14: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 15: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(5)->Append(10);
        std::cout << "Test 16: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.Append(7)->Append(8);
        seq[0] = 9;
        std::cout << "Test 17: Operator [] - ";
        if (seq[0] == 9 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.To_String();
        std::cout << "Test 18: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with exception: " << e.what() << "\n";
    }
    try {
        ListSequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 19: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 19: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 19: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testArraySequence() {
    std::cout << "=== Testing ArraySequence ===\n";
    try {
        ArraySequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0 && seq.GetCapacity() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ArraySequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq(2);
        std::cout << "Test 3: Constructor with size 2 - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 0 && seq.Get(1) == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq1;
        seq1.Append(10)->Append(20);
        ArraySequence<int> seq2(seq1);
        std::cout << "Test 4: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1);
        seq.Get(1);
        std::cout << "Test 5: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 6: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 6: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2);
        std::cout << "Test 7: Append - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Prepend(2)->Prepend(1);
        std::cout << "Test 8: Prepend - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(3);
        seq.InsertAt(2, 1);
        std::cout << "Test 9: InsertAt - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2);
        seq.Set(10, 1);
        std::cout << "Test 10: Set - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 11: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq1;
        seq1.Append(1)->Append(2);
        ArraySequence<int> seq2;
        seq2.Append(3)->Append(4);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 12: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 13: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3)->Append(4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 14: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 15: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(5)->Append(10);
        std::cout << "Test 16: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(7)->Append(8);
        seq[0] = 9;
        std::cout << "Test 17: Operator [] - ";
        if (seq[0] == 9 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.To_String();
        std::cout << "Test 18: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 19: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 19: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 19: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ArraySequence<int> seq;
        seq.Append(1)->Append(2);
        std::cout << "Test 20: GetCapacity - ";
        if (seq.GetCapacity() >= 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 20: Failed with exception: " << e.what() << "\n";
    }
}
void testImmutableArraySequence() {
    std::cout << "=== Testing ImmutableArraySequence ===\n";
    try {
        ImmutableArraySequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableArraySequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 10, 20 };
        ImmutableArraySequence<int> seq1(items, 2);
        ImmutableArraySequence<int> seq2(seq1);
        std::cout << "Test 3: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1 };
        ImmutableArraySequence<int> seq(items, 1);
        seq.Get(1);
        std::cout << "Test 4: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 4: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ImmutableArraySequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 5: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ImmutableArraySequence<int> seq;
        ImmutableArraySequence<int>* newSeq = dynamic_cast<ImmutableArraySequence<int>*>(seq.Append(1));
        std::cout << "Test 6: Append immutability - ";
        if (seq.GetLength() == 0 && newSeq->GetLength() == 1 && newSeq->Get(0) == 1) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        ImmutableArraySequence<int> seq;
        ImmutableArraySequence<int>* newSeq = dynamic_cast<ImmutableArraySequence<int>*>(seq.Prepend(1));
        std::cout << "Test 7: Prepend immutability - ";
        if (seq.GetLength() == 0 && newSeq->GetLength() == 1 && newSeq->Get(0) == 1) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 3 };
        ImmutableArraySequence<int> seq(items, 2);
        ImmutableArraySequence<int>* newSeq = dynamic_cast<ImmutableArraySequence<int>*>(seq.InsertAt(2, 1));
        std::cout << "Test 8: InsertAt immutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 3 &&
            newSeq->GetLength() == 3 && newSeq->Get(0) == 1 && newSeq->Get(1) == 2 && newSeq->Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2 };
        ImmutableArraySequence<int> seq(items, 2);
        ImmutableArraySequence<int>* newSeq = dynamic_cast<ImmutableArraySequence<int>*>(seq.Set(10, 1));
        std::cout << "Test 9: Set immutability - ";
        if (seq.GetLength() == 2 && seq.Get(1) == 2 &&
            newSeq->GetLength() == 2 && newSeq->Get(0) == 1 && newSeq->Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableArraySequence<int> seq(items, 3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 10: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items1[] = { 1, 2 };
        int items2[] = { 3, 4 };
        ImmutableArraySequence<int> seq1(items1, 2);
        ImmutableArraySequence<int> seq2(items2, 2);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 11: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableArraySequence<int> seq(items, 3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 12: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3, 4 };
        ImmutableArraySequence<int> seq(items, 4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 13: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableArraySequence<int> seq(items, 3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 14: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 5, 10 };
        ImmutableArraySequence<int> seq(items, 2);
        std::cout << "Test 15: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 7, 8 };
        ImmutableArraySequence<int> seq(items, 2);
        std::cout << "Test 16: Operator [] (read) - ";
        if (seq[0] == 7 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        ImmutableArraySequence<int> seq;
        seq.To_String();
        std::cout << "Test 17: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        ImmutableArraySequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 18: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 18: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testMutableArraySequence() {
    std::cout << "=== Testing MutableArraySequence ===\n";
    try {
        MutableArraySequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        MutableArraySequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq1;
        seq1.Append(10)->Append(20);
        MutableArraySequence<int> seq2(seq1);
        std::cout << "Test 3: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1);
        seq.Get(1);
        std::cout << "Test 4: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 4: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 5: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(2);
        std::cout << "Test 6: Append mutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Prepend(2)->Prepend(1);
        std::cout << "Test 7: Prepend mutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(3);
        seq.InsertAt(2, 1);
        std::cout << "Test 8: InsertAt mutability - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(2);
        seq.Set(10, 1);
        std::cout << "Test 9: Set mutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 10: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq1;
        seq1.Append(1)->Append(2);
        MutableArraySequence<int> seq2;
        seq2.Append(3)->Append(4);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 11: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 12: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3)->Append(4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 13: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 14: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(5)->Append(10);
        std::cout << "Test 15: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.Append(7)->Append(8);
        seq[0] = 9;
        std::cout << "Test 16: Operator [] - ";
        if (seq[0] == 9 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.To_String();
        std::cout << "Test 17: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableArraySequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 18: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 18: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testImmutableListSequence() {
    std::cout << "=== Testing ImmutableListSequence ===\n";
    try {
        ImmutableListSequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableListSequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 10, 20 };
        ImmutableListSequence<int> seq1(items, 2);
        ImmutableListSequence<int> seq2(seq1);
        std::cout << "Test 3: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1 };
        ImmutableListSequence<int> seq(items, 1);
        seq.Get(1);
        std::cout << "Test 4: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 4: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ImmutableListSequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 5: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        ImmutableListSequence<int> seq;
        ImmutableListSequence<int>* newSeq = dynamic_cast<ImmutableListSequence<int>*>(seq.Append(1));
        std::cout << "Test 6: Append immutability - ";
        if (seq.GetLength() == 0 && newSeq->GetLength() == 1 && newSeq->Get(0) == 1) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        ImmutableListSequence<int> seq;
        ImmutableListSequence<int>* newSeq = dynamic_cast<ImmutableListSequence<int>*>(seq.Prepend(1));
        std::cout << "Test 7: Prepend immutability - ";
        if (seq.GetLength() == 0 && newSeq->GetLength() == 1 && newSeq->Get(0) == 1) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 3 };
        ImmutableListSequence<int> seq(items, 2);
        ImmutableListSequence<int>* newSeq = dynamic_cast<ImmutableListSequence<int>*>(seq.InsertAt(2, 1));
        std::cout << "Test 8: InsertAt immutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 3 &&
            newSeq->GetLength() == 3 && newSeq->Get(0) == 1 && newSeq->Get(1) == 2 && newSeq->Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2 };
        ImmutableListSequence<int> seq(items, 2);
        ImmutableListSequence<int>* newSeq = dynamic_cast<ImmutableListSequence<int>*>(seq.Set(10, 1));
        std::cout << "Test 9: Set immutability - ";
        if (seq.GetLength() == 2 && seq.Get(1) == 2 &&
            newSeq->GetLength() == 2 && newSeq->Get(0) == 1 && newSeq->Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete newSeq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableListSequence<int> seq(items, 3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 10: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items1[] = { 1, 2 };
        int items2[] = { 3, 4 };
        ImmutableListSequence<int> seq1(items1, 2);
        ImmutableListSequence<int> seq2(items2, 2);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 11: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableListSequence<int> seq(items, 3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 12: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3, 4 };
        ImmutableListSequence<int> seq(items, 4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 13: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        ImmutableListSequence<int> seq(items, 3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 14: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 5, 10 };
        ImmutableListSequence<int> seq(items, 2);
        std::cout << "Test 15: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 7, 8 };
        ImmutableListSequence<int> seq(items, 2);
        std::cout << "Test 16: Operator [] (read) - ";
        if (seq[0] == 7 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        ImmutableListSequence<int> seq;
        seq.To_String();
        std::cout << "Test 17: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        ImmutableListSequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 18: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 18: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testMutableListSequence() {
    std::cout << "=== Testing MutableListSequence ===\n";
    try {
        MutableListSequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        MutableListSequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq1;
        seq1.Append(10)->Append(20);
        MutableListSequence<int> seq2(seq1);
        std::cout << "Test 3: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1);
        seq.Get(1);
        std::cout << "Test 4: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 4: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 5: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(2);
        std::cout << "Test 6: Append mutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Prepend(2)->Prepend(1);
        std::cout << "Test 7: Prepend mutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(3);
        seq.InsertAt(2, 1);
        std::cout << "Test 8: InsertAt mutability - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(2);
        seq.Set(10, 1);
        std::cout << "Test 9: Set mutability - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 10: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq1;
        seq1.Append(1)->Append(2);
        MutableListSequence<int> seq2;
        seq2.Append(3)->Append(4);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 11: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 12: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3)->Append(4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 13: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(1)->Append(2)->Append(3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 14: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(5)->Append(10);
        std::cout << "Test 15: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.Append(7)->Append(8);
        seq[0] = 9;
        std::cout << "Test 16: Operator [] - ";
        if (seq[0] == 9 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.To_String();
        std::cout << "Test 17: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        MutableListSequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 18: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 18: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testAdaptiveSequence() {
    std::cout << "=== Testing AdaptiveSequence ===\n";
    try {
        AdaptiveSequence<int> seq;
        std::cout << "Test 1: Default constructor - ";
        if (seq.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        AdaptiveSequence<int> seq(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 10, 20 };
        AdaptiveSequence<int> seq1(items, 2);
        AdaptiveSequence<int> seq2(seq1);
        std::cout << "Test 3: Copy constructor - ";
        if (seq2.GetLength() == 2 && seq2.Get(0) == 10 && seq2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1 };
        AdaptiveSequence<int> seq(items, 1);
        seq.Get(1);
        std::cout << "Test 4: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 4: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.GetFirst();
        std::cout << "Test 5: GetFirst on empty sequence - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: GetFirst on empty sequence - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.Append(1)->Append(2);
        std::cout << "Test 6: Append - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.Prepend(2)->Prepend(1);
        std::cout << "Test 7: Prepend - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.Append(1)->Append(3);
        seq.InsertAt(2, 1);
        std::cout << "Test 8: InsertAt - ";
        if (seq.GetLength() == 3 && seq.Get(0) == 1 && seq.Get(1) == 2 && seq.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.Append(1)->Append(2);
        seq.Set(10, 1);
        std::cout << "Test 9: Set - ";
        if (seq.GetLength() == 2 && seq.Get(0) == 1 && seq.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        AdaptiveSequence<int> seq(items, 3);
        Sequence<int>* sub = seq.GetSubsequence(1, 2);
        std::cout << "Test 10: GetSubsequence - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items1[] = { 1, 2 };
        int items2[] = { 3, 4 };
        AdaptiveSequence<int> seq1(items1, 2);
        AdaptiveSequence<int> seq2(items2, 2);
        Sequence<int>* result = seq1.Concat(&seq2);
        std::cout << "Test 11: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        AdaptiveSequence<int> seq(items, 3);
        auto doubleFunc = [](int x) { return x * 2; };
        Sequence<int>* result = seq.Map(doubleFunc);
        std::cout << "Test 12: Map (double) - ";
        if (result->GetLength() == 3 && result->Get(0) == 2 && result->Get(1) == 4 && result->Get(2) == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3, 4 };
        AdaptiveSequence<int> seq(items, 4);
        auto isEven = [](int x) { return x % 2 == 0; };
        Sequence<int>* result = seq.Where(isEven);
        std::cout << "Test 13: Where (even numbers) - ";
        if (result->GetLength() == 2 && result->Get(0) == 2 && result->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        AdaptiveSequence<int> seq(items, 3);
        auto sum = [](int a, int b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        std::cout << "Test 14: Reduce (sum) - ";
        if (result == 6) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 5, 10 };
        AdaptiveSequence<int> seq(items, 2);
        std::cout << "Test 15: To_String - ";
        std::cout << "Output: ";
        seq.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 7, 8 };
        AdaptiveSequence<int> seq(items, 2);
        seq[0] = 9;
        std::cout << "Test 16: Operator [] - ";
        if (seq[0] == 9 && seq[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.To_String();
        std::cout << "Test 17: Empty sequence To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 17: Failed with exception: " << e.what() << "\n";
    }
    try {
        AdaptiveSequence<int> seq;
        seq.InsertAt(1, 2);
        std::cout << "Test 18: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 18: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 18: Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testSegmentedList() {
    std::cout << "=== Testing SegmentedList ===\n";
    try {
        SegmentedList<int> list;
        std::cout << "Test 1: Default constructor - ";
        if (list.GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        SegmentedList<int> list(items, 3);
        std::cout << "Test 2: Constructor with array [1, 2, 3] - ";
        if (list.GetLength() == 3 && list.Get(0) == 1 && list.Get(1) == 2 && list.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 10, 20 };
        SegmentedList<int> list1(items, 2);
        SegmentedList<int> list2(list1);
        std::cout << "Test 3: Copy constructor - ";
        if (list2.GetLength() == 2 && list2.Get(0) == 10 && list2.Get(1) == 20) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1 };
        SegmentedList<int> list(items, 1);
        list.Get(1);
        std::cout << "Test 4: Get with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 4: Get with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.GetFirst();
        std::cout << "Test 5: GetFirst on empty list - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 5: GetFirst on empty list - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.Append(1);
        list.Append(2);
        list.Append(3);
        std::cout << "Test 6: Append - ";
        if (list.GetLength() == 3 && list.Get(0) == 1 && list.Get(1) == 2 && list.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.Prepend(2);
        list.Prepend(1);
        std::cout << "Test 7: Prepend - ";
        if (list.GetLength() == 2 && list.Get(0) == 1 && list.Get(1) == 2) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.Append(1);
        list.Append(3);
        list.InsertAt(2, 1);
        std::cout << "Test 8: InsertAt - ";
        if (list.GetLength() == 3 && list.Get(0) == 1 && list.Get(1) == 2 && list.Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.Append(1);
        list.Append(2);
        list.Set(10, 1);
        std::cout << "Test 9: Set - ";
        if (list.GetLength() == 2 && list.Get(0) == 1 && list.Get(1) == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 1, 2, 3 };
        SegmentedList<int> list(items, 3);
        SegmentedList<int>* sub = (SegmentedList<int>*)list.GetSubsequence(1, 2);
        std::cout << "Test 10: GetSubList - ";
        if (sub->GetLength() == 2 && sub->Get(0) == 2 && sub->Get(1) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete sub;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items1[] = { 1, 2 };
        int items2[] = { 3, 4 };
        SegmentedList<int> list1(items1, 2);
        SegmentedList<int> list2(items2, 2);
        SegmentedList<int>* result = (SegmentedList<int>*)list1.Concat(&list2);
        std::cout << "Test 11: Concat - ";
        if (result->GetLength() == 4 && result->Get(0) == 1 && result->Get(1) == 2 &&
            result->Get(2) == 3 && result->Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 5, 10 };
        SegmentedList<int> list(items, 2);
        std::cout << "Test 12: To_String - ";
        std::cout << "Output: ";
        list.To_String();
        std::cout << "Passed (check output [5; 10])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }
    try {
        int items[] = { 7, 8 };
        SegmentedList<int> list(items, 2);
        list[0] = 9;
        std::cout << "Test 13: Operator [] - ";
        if (list[0] == 9 && list[1] == 8) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.To_String();
        std::cout << "Test 14: Empty list To_String - Passed (check output [])\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.InsertAt(1, 2);
        std::cout << "Test 15: InsertAt with invalid index - Failed (no exception)\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Test 15: InsertAt with invalid index - Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with unexpected exception: " << e.what() << "\n";
    }
    try {
        SegmentedList<int> list;
        list.Append(1);
        list.Append(2);
        list.Append(3);
        list.Append(4);
        std::cout << "Test 16: Multiple segments - ";
        if (list.GetLength() == 4 && list.Get(0) == 1 && list.Get(1) == 2 &&
            list.Get(2) == 3 && list.Get(3) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 16: Failed with exception: " << e.what() << "\n";
    }
}
void FullTests() {
    testDynamicArray();
    testLinkedList();
    testListSequence();
    testArraySequence();
    testImmutableArraySequence();
    testMutableArraySequence();
    testImmutableListSequence();
    testMutableListSequence();
    testSegmentedList();
    testAdaptiveSequence();
}