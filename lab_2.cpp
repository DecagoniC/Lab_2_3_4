#include <iostream>
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
    //FullTests();
    int m[] = { 2,3,4,1,7,6,5,9,0,8 };
    Stack<int> A(m,10);
    A.To_String();
    return 0;
}