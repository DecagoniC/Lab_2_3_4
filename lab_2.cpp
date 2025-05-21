#include <iostream>
#include <chrono>
#include <cassert>
#include <sstream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"
#include "SegmentedList.h"
#include "TESTS.h"
#include "AdaptiveSequence.h"
#include "UI.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "string"
#include "TreeTEST.h" 
#include "Set.h"
#include "SetTEST.h"


int plus(int y, int x) {
    return x + y;
}
int fun(int x) {
    return x * x;
}
int bb(int a) {
    return 4;
}
bool pred(int a) {
    return a > 10;
}
int main() {
    setlocale(LC_ALL, "Russian");
    testSet();
    
    return 0;
}