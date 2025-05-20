#pragma once
#include <iostream>
#include <stdexcept>
#include "BinaryTree.h"
#include <algorithm>
void testBinaryTreeRemove() {
    std::cout << "=== Binary Tree Deletion Testing ===\n";

    // Test 1: Deleting from an empty tree
    try {
        BinaryTree<int> tree;
        std::cout << "Test 1: Deleting from empty tree - ";
        tree.remove(42);
        if (tree.isEmpty() && tree.getNodeCount() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Deleting the root node
    try {
        BinaryTree<int> tree;
        tree.add(10);
        std::cout << "Test 2: Deleting root node - ";
        tree.remove(10);
        if (tree.isEmpty() && tree.getNodeCount() == 0 && tree.getHeight() == 0 && !tree.contains(10)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Deleting a leaf node
    try {
        int items[] = { 10, 5, 15, 3, 7 };
        BinaryTree<int> tree(items, 5);
        std::cout << "Test 3: Deleting leaf node - ";
        tree.remove(3);
        auto seq = tree.LNR();
        int expected[] = { 5, 7, 10, 15 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 4 || tree.getNodeCount() != 4 || tree.getHeight() > 2) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq->GetLength(); ++i) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct && !tree.contains(3)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Deleting a node with one child
    try {
        int items[] = { 10, 5, 15, 3 };
        BinaryTree<int> tree(items, 4);
        std::cout << "Test 4: Deleting node with one child - ";
        tree.remove(5);
        auto seq = tree.LNR();
        int expected[] = { 3, 10, 15 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 3 || tree.getNodeCount() != 3 || tree.getHeight() > 2) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq->GetLength(); ++i) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct && !tree.contains(5)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Deleting a node with two children
    try {
        int items[] = { 10, 5, 15, 3, 7, 12, 18 };
        BinaryTree<int> tree(items, 7);
        std::cout << "Test 5: Deleting node with two children - ";
        tree.remove(10);
        auto seq = tree.LNR();
        int expected[] = { 3, 5, 7, 12, 15, 18 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 6 || tree.getNodeCount() != 6 || tree.getHeight() > 3) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq->GetLength(); ++i) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct && !tree.contains(10)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: Deleting a non-existent element
    try {
        int items[] = { 10, 5, 15 };
        BinaryTree<int> tree(items, 3);
        std::cout << "Test 6: Deleting non-existent element - ";
        tree.remove(20);
        auto seq = tree.LNR();
        int expected[] = { 5, 10, 15 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 3 || tree.getNodeCount() != 3 || tree.getHeight() > 2) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq->GetLength(); ++i) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }

    // Test 7: Balancing after deletion
    try {
        int items[] = { 10, 5, 15, 3, 7, 12, 18, 1 };
        BinaryTree<int> tree(items, 8);
        std::cout << "Test 7: Balancing after deletion - ";
        tree.remove(15);
        auto seq = tree.LNR();
        int expected[] = { 1, 3, 5, 7, 10, 12, 18 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 7 || tree.getNodeCount() != 7 || tree.getHeight() > 3) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq->GetLength(); ++i) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct && !tree.contains(15)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }

    // Test 8: Multiple deletions
    try {
        int items[] = { 10, 5, 15, 3, 7, 12, 18 };
        BinaryTree<int> tree(items, 7);
        std::cout << "Test 8: Multiple deletions - ";
        tree.remove(5);
        tree.remove(15);
        tree.remove(3);
        auto seq = tree.LNR();
        int expected[] = { 7, 10, 12, 18 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 4 || tree.getNodeCount() != 4 || tree.getHeight() > 2) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq->GetLength(); ++i) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct && !tree.contains(5) && !tree.contains(15) && !tree.contains(3)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }

    // Test 9: Deleting all elements
    try {
        int items[] = { 10, 5, 15 };
        BinaryTree<int> tree(items, 3);
        std::cout << "Test 9: Deleting all elements - ";
        tree.remove(5);
        tree.remove(10);
        tree.remove(15);
        if (tree.isEmpty() && tree.getNodeCount() == 0 && tree.getHeight() == 0) {
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
void testBinaryTreeReduce() {
    std::cout << "=== Binary Tree Reduce Testing ===\n";
    // Test 1: Sum reduction
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3);
        int sum = tree.Reduce(
            [](const int& acc, const int& val) { return acc + val; }, 0
        );
        std::cout << "Test 1: Sum reduction - ";
        if (sum == 33) { // 3 + 5 + 10 + 15
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Product reduction
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3);
        int product = tree.Reduce(
            [](const int& acc, const int& val) { return acc * val; }, 1
        );
        std::cout << "Test 2: Product reduction - ";
        if (product == 2250) { // 3 * 5 * 10 * 15
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Maximum reduction
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3);
        int max = tree.Reduce(
            [](const int& acc, const int& val) { return std::max(acc, val); },
            0
        );
        std::cout << "Test 3: Maximum reduction - ";
        if (max == 15) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Empty tree reduction
    try {
        BinaryTree<int> emptyTree;
        int emptySum = emptyTree.Reduce(
            [](const int& acc, const int& val) { return acc + val; }, 0
        );
        std::cout << "Test 4: Empty tree reduction - ";
        if (emptySum == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Null function exception
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3);
        std::cout << "Test 5: Null function exception - ";
        tree.Reduce(std::function<int(const int&, const int&)>(nullptr), 0);
        std::cout << "Failed\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testBinaryTreeMap() {
    std::cout << "=== Binary Tree Map Testing ===\n";

    // Test 1: Map integers to their squares
    try {
        BinaryTree<int> tree;
        tree.add(2)->add(3)->add(1);
        BinaryTree<int>* result = tree.map<int>([](const int& x) { return x * x; });
        Sequence<int>* lnr = result->LNR();
        ArraySequence<int>* arrSeq = dynamic_cast<ArraySequence<int>*>(lnr);
        std::cout << "Test 1: Map to squares - ";
        if (arrSeq && arrSeq->GetLength() == 3 && arrSeq->Get(0) == 1 && arrSeq->Get(1) == 4 && arrSeq->Get(2) == 9) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Map integers to strings
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2)->add(3);
        BinaryTree<std::string>* result = tree.map<std::string>([](const int& x) { return std::to_string(x); });
        Sequence<std::string>* lnr = result->LNR();
        ArraySequence<std::string>* arrSeq = dynamic_cast<ArraySequence<std::string>*>(lnr);
        std::cout << "Test 2: Map to strings - ";
        if (arrSeq && arrSeq->GetLength() == 3 && arrSeq->Get(0) == "1" && arrSeq->Get(1) == "2" && arrSeq->Get(2) == "3") {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: FAILED with exception: " << e.what() << "\n";
    }

    // Test 3: Empty tree mapping
    try {
        BinaryTree<int> tree;
        BinaryTree<int>* result = tree.map<int>([](const int& x) { return x + 1; });
        Sequence<int>* lnr = result->LNR();
        std::cout << "Test 3: Empty tree mapping - ";
        if (lnr && lnr->GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Original tree unchanged
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2)->add(3);
        BinaryTree<int>* result = tree.map<int>([](const int& x) { return x + 1; });
        Sequence<int>* lnr = tree.LNR();
        ArraySequence<int>* arrSeq = dynamic_cast<ArraySequence<int>*>(lnr);
        std::cout << "Test 4: Original tree unchanged - ";
        if (arrSeq && arrSeq->GetLength() == 3 && arrSeq->Get(0) == 1 && arrSeq->Get(1) == 2 && arrSeq->Get(2) == 3) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Null function exception
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2);
        std::cout << "Test 5: Null function exception - ";
        tree.map<int>(std::function<int(const int&)>(nullptr));
        std::cout << "Failed\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testBinaryTreeWhere() {
    std::cout << "=== Binary Tree Where Testing ===\n";

    // Test 1: Filter even numbers
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2)->add(3)->add(4)->add(5);
        BinaryTree<int>* result = tree.where([](const int& x) { return x % 2 == 0; });
        Sequence<int>* lnr = result->LNR();
        ArraySequence<int>* arrSeq = dynamic_cast<ArraySequence<int>*>(lnr);
        std::cout << "Test 1: Filter even numbers - ";
        if (arrSeq && arrSeq->GetLength() == 2 && arrSeq->Get(0) == 2 && arrSeq->Get(1) == 4) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Filter numbers greater than 3
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2)->add(3)->add(4)->add(5);
        BinaryTree<int>* result = tree.where([](const int& x) { return x > 3; });
        Sequence<int>* lnr = result->LNR();
        ArraySequence<int>* arrSeq = dynamic_cast<ArraySequence<int>*>(lnr);
        std::cout << "Test 2: Filter numbers > 3 - ";
        if (arrSeq && arrSeq->GetLength() == 2 && arrSeq->Get(0) == 4 && arrSeq->Get(1) == 5) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Empty tree filtering
    try {
        BinaryTree<int> tree;
        BinaryTree<int>* result = tree.where([](const int& x) { return x > 0; });
        Sequence<int>* lnr = result->LNR();
        std::cout << "Test 3: Empty tree filtering - ";
        if (lnr && lnr->GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: No matches in filtering
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2)->add(3);
        BinaryTree<int>* result = tree.where([](const int& x) { return x > 10; });
        Sequence<int>* lnr = result->LNR();
        std::cout << "Test 4: No matches in filtering - ";
        if (lnr && lnr->GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete lnr;
        delete result;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Null predicate exception
    try {
        BinaryTree<int> tree;
        tree.add(1)->add(2);
        std::cout << "Test 5: Null predicate exception - ";
        tree.where(std::function<bool(const int&)>(nullptr));
        std::cout << "Failed\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Passed\n";
    }
    catch (const std::exception& e) {
        std::cout << "Failed with unexpected exception: " << e.what() << "\n";
    }
}
void testBinaryTreeCompareSubtrees() {
    std::cout << "=== Binary Tree CompareSubtrees Testing ===\n";

    // Test 1: Identical subtrees
    try {
        BinaryTree<int> tree1;
        tree1.add(10)->add(5)->add(15);
        BinaryTree<int> tree2;
        tree2.add(10)->add(5)->add(15);
        std::cout << "Test 1: Identical subtrees - ";
        if (tree1.compareSubtrees(tree1.getRoot(), tree2.getRoot())) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Non-identical subtrees
    try {
        BinaryTree<int> tree1;
        tree1.add(10)->add(5)->add(15);
        BinaryTree<int> tree2;
        tree2.add(10)->add(6)->add(15);
        std::cout << "Test 2: Non-identical subtrees - ";
        if (!tree1.compareSubtrees(tree1.getRoot(), tree2.getRoot())) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: One null subtree
    try {
        BinaryTree<int> tree1;
        tree1.add(10);
        BinaryTree<int> tree2;
        std::cout << "Test 3: One null subtree - ";
        if (!tree1.compareSubtrees(tree1.getRoot(), nullptr)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Both null subtrees
    try {
        BinaryTree<int> tree1;
        BinaryTree<int> tree2;
        std::cout << "Test 4: Both null subtrees - ";
        if (tree1.compareSubtrees(nullptr, nullptr)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Same values, different structure
    try {
        BinaryTree<int> tree1;
        tree1.add(10)->add(5)->add(15)->add(12);
        BinaryTree<int> tree3;
        tree3.add(15)->add(12)->add(10)->add(5);

        std::cout << "Test 5: Same values, different structure - ";
        if (!tree1.compareSubtrees(tree1.getRoot(), tree3.getRoot())) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (...) {
        std::cout << "Test 5: Failed with exception\n";
    }
}
void testBinaryTreeContainsSubtree() {
    std::cout << "=== Binary Tree ContainsSubtree Testing ===\n";

    // Test 1: Existing subtree
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3)->add(7);
        BinaryTree<int> subtree;
        subtree.add(5)->add(3)->add(7);
        std::cout << "Test 1: Existing subtree - ";
        if (tree.containsSubtree(subtree)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Non-existing subtree
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15);
        BinaryTree<int> subtree;
        subtree.add(5)->add(4)->add(6);
        std::cout << "Test 2: Non-existing subtree - ";
        if (!tree.containsSubtree(subtree)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Empty subtree
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5);
        BinaryTree<int> subtree;
        std::cout << "Test 3: Empty subtree - ";
        if (tree.containsSubtree(subtree)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: Single-node subtree
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15);
        BinaryTree<int> subtree;
        subtree.add(10);
        std::cout << "Test 4: Single-node subtree - ";
        if (tree.containsSubtree(subtree)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: Complex subtree with multiple nodes
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3)->add(7)->add(12)->add(20);
        BinaryTree<int> subtree;
        subtree.add(15)->add(12)->add(20);
        std::cout << "Test 5: Complex subtree - ";
        if (tree.containsSubtree(subtree)) {
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


void testBinaryTree() {
    std::cout << "=== Testing BinaryTree ===\n";  
    // Test 1: Default constructor
    try {
        BinaryTree<int> tree;
        std::cout << "Test 1: Default constructor - ";
        if (tree.isEmpty() && tree.getNodeCount() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 1: Failed with exception: " << e.what() << "\n";
    }

    // Test 2: Add elements
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3)->add(7);
        std::cout << "Test 2: Add elements - ";
        if (tree.getNodeCount() == 5 && tree.contains(10) && tree.contains(5) &&
            tree.contains(15) && tree.contains(3) && tree.contains(7)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 2: Failed with exception: " << e.what() << "\n";
    }

    // Test 3: Array initialization
    try {
        int items[] = { 8, 4, 12, 2, 6, 10, 14 };
        BinaryTree<int> tree(items, 7);
        std::cout << "Test 3: Array initialization - ";
        if (tree.getNodeCount() == 7 && tree.contains(8) && tree.contains(4) &&
            tree.contains(12) && tree.contains(2) && tree.contains(6) &&
            tree.contains(10) && tree.contains(14)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 3: Failed with exception: " << e.what() << "\n";
    }

    // Test 4: LNR (in-order) traversal
    try {
        int items[] = { 5, 3, 7, 1, 4, 6, 8 };
        BinaryTree<int> tree(items, 7);
        auto seq = tree.LNR();
        std::cout << "Test 4: LNR traversal - ";
        int expected[] = { 1, 3, 4, 5, 6, 7, 8 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 7) correct = false;
        else {
            for (int i = 0; i < seq->GetLength(); i++) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct) std::cout << "Passed\n";
        else std::cout << "Failed\n";
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 4: Failed with exception: " << e.what() << "\n";
    }

    // Test 5: NLR (pre-order) traversal
    try {
        int items[] = { 5, 3, 7, 1, 4, 6, 8 };
        BinaryTree<int> tree(items, 7);
        auto seq = tree.NLR();
        std::cout << "Test 5: NLR traversal - ";
        int expected[] = { 5, 3, 1, 4, 7, 6, 8 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 7) correct = false;
        else {
            for (int i = 0; i < seq->GetLength(); i++) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct) std::cout << "Passed\n";
        else std::cout << "Failed\n";
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 5: Failed with exception: " << e.what() << "\n";
    }

    // Test 6: RLN (post-order) traversal
    try {
        int items[] = { 5, 3, 7, 1, 4, 6, 8 };
        BinaryTree<int> tree(items, 7);
        auto seq = tree.RLN();
        std::cout << "Test 6: RLN traversal - ";
        int expected[] = { 1, 4, 3, 6, 8, 7, 5 };
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 7) correct = false;
        else {
            for (int i = 0; i < seq->GetLength(); i++) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != expected[i]) correct = false;
            }
        }
        if (correct) std::cout << "Passed\n";
        else std::cout << "Failed\n";
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 6: Failed with exception: " << e.what() << "\n";
    }

    // Test 7: Tree height (corrected for height starting from 0)
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15)->add(3)->add(7)->add(12)->add(18);
        std::cout << "Test 7: Tree height - ";
        int height = tree.getHeight();
        if (height >= 2 && height <= 3) { // Balanced tree with 7 nodes, height from 0, log2(7) ~ 2-3
            std::cout << "Passed (height=" << height << ")\n";
        }
        else {
            std::cout << "Failed (height=" << height << ")\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 7: Failed with exception: " << e.what() << "\n";
    }

    // Test 8: Contains missing element
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(5)->add(15);
        std::cout << "Test 8: Contains missing element - ";
        if (!tree.contains(7)) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 8: Failed with exception: " << e.what() << "\n";
    }

    // Test 9: Balance check
    try {
        BinaryTree<int> tree;
        for (int i = 1; i <= 15; i++) tree.add(i);
        std::cout << "Test 9: Balance check - ";
        int height = tree.getHeight();
        if (height <= 4) { // For AVL tree, height should be ~log2(15) - 1 <= 4 (from 0)
            std::cout << "Passed (height=" << height << ")\n";
        }
        else {
            std::cout << "Failed (height=" << height << ")\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 9: Failed with exception: " << e.what() << "\n";
    }

    // Test 10: Empty tree traversal
    try {
        BinaryTree<int> tree;
        auto seq = tree.LNR();
        std::cout << "Test 10: Empty tree LNR traversal - ";
        if (seq == nullptr || seq->GetLength() == 0) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 10: Failed with exception: " << e.what() << "\n";
    }

    // Test 11: Single node tree
    try {
        BinaryTree<int> tree;
        tree.add(42);
        auto seq = tree.LNR();
        std::cout << "Test 11: Single node tree - ";
        if (seq != nullptr && seq->GetLength() == 1 &&
            (*dynamic_cast<ArraySequence<int>*>(seq))[0] == 42 &&
            tree.getNodeCount() == 1 && tree.getHeight() == 0) { // Height 0 for single node
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 11: Failed with exception: " << e.what() << "\n";
    }

    // Test 12: Duplicate elements
    try {
        BinaryTree<int> tree;
        tree.add(10)->add(10)->add(10);
        std::cout << "Test 12: Duplicate elements - ";
        if (tree.getNodeCount() == 1 && tree.contains(10) && tree.getHeight() == 0) { // Height 0
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 12: Failed with exception: " << e.what() << "\n";
    }

    // Test 13: Large tree
    try {
        BinaryTree<int> tree;
        for (int i = 1; i <= 100; i++) tree.add(i);
        std::cout << "Test 13: Large tree - ";
        if (tree.getNodeCount() == 100 && tree.contains(1) && tree.contains(50) &&
            tree.contains(100) && tree.getHeight() <= 7) { // Height <= log2(100) - 1 ~ 7
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Test 13: Failed with exception: " << e.what() << "\n";
    }

    // Test 14: Unbalanced tree
    try {
        BinaryTree<int> tree;
        for (int i = 1; i <= 10; i++) tree.add(i * 10);
        std::cout << "Test 14: Unbalanced tree - ";
        auto seq = tree.LNR();
        bool correct = true;
        if (seq == nullptr || seq->GetLength() != 10) correct = false;
        else {
            for (int i = 0; i < seq->GetLength(); i++) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq))[i] != (i + 1) * 10) correct = false;
            }
        }
        if (correct && seq->GetLength() == 10) {
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq;
    }
    catch (const std::exception& e) {
        std::cout << "Test 14: Failed with exception: " << e.what() << "\n";
    }

    // Test 15: Copy constructor
    try {
        int items[] = { 10, 5, 15 };
        BinaryTree<int> tree1(items, 3);
        BinaryTree<int> tree2(tree1);
        std::cout << "Test 15: Copy constructor - ";
        auto seq1 = tree1.LNR();
        auto seq2 = tree2.LNR();
        bool correct = true;
        if (seq1 == nullptr || seq2 == nullptr || seq1->GetLength() != seq2->GetLength()) {
            correct = false;
        }
        else {
            for (int i = 0; i < seq1->GetLength(); i++) {
                if ((*dynamic_cast<ArraySequence<int>*>(seq1))[i] !=
                    (*dynamic_cast<ArraySequence<int>*>(seq2))[i]) correct = false;
            }
        }
        if (correct && tree2.getNodeCount() == 3 && tree2.getHeight() <= 2) { // Height <= 2 from 0
            std::cout << "Passed\n";
        }
        else {
            std::cout << "Failed\n";
        }
        delete seq1;
        delete seq2;
    }
    catch (const std::exception& e) {
        std::cout << "Test 15: Failed with exception: " << e.what() << "\n";
    }
    
    testBinaryTreeRemove();
    testBinaryTreeReduce();
    testBinaryTreeMap();
    testBinaryTreeWhere();
    testBinaryTreeCompareSubtrees();
    testBinaryTreeContainsSubtree();
}