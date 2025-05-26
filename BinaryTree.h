#pragma once
#include <iostream>
#include <stdexcept>
#include "ArraySequence.h"
#include "Stack.h"

template <typename T>
class BinaryTree {
protected:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node* parent;
        int height;
        Node() : value(T()), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
        Node(T item) : value(item), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
        Node(T item, Node* parent) : value(item), left(nullptr), right(nullptr), parent(parent), height(0) {}
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };

    Node* root;
    int height;
    int nodeCount;
    int countNodes(const Node* root) {
        if (!root) return 0;
        Stack<const Node*> stack;
        stack.Push(root);
        int count = 0;

        while (!stack.IsEmpty()) {
            const Node* node = stack.Top();
            stack.Pop();
            count++;

            if (node->left) stack.Push(node->left);
            if (node->right) stack.Push(node->right);
        }
        return count;
    }
    void updateHeight(Node* node) {
        if (!node) return;
        int leftHeight = node->left ? node->left->height : -1;
        int rightHeight = node->right ? node->right->height : -1;
        node->height = std::max(leftHeight, rightHeight) + 1;
    }
    int getBalanceFactor(Node* node) {
        if (!node) return 0;
        int leftHeight = (node->left) ? node->left->height : -1;
        int rightHeight = (node->right) ? node->right->height : -1;
        return leftHeight - rightHeight;
    }
    Node* copyTree(const Node* sourceRoot) const {
        if (!sourceRoot) return nullptr;

        struct StackItem {
            const Node* srcNode;
            Node** dstPtr;
            Node* parent;
        };

        Stack<StackItem> stack;
        Node* newRoot = nullptr;

        stack.Push({ sourceRoot, &newRoot, nullptr });

        while (!stack.IsEmpty()) {
            auto [srcNode, dstPtr, parent] = stack.Top();
            stack.Pop();

            if (!srcNode) continue;

            *dstPtr = new Node(srcNode->value, parent);
            (*dstPtr)->height = srcNode->height;

            stack.Push({ srcNode->right, &((*dstPtr)->right), *dstPtr });
            stack.Push({ srcNode->left, &((*dstPtr)->left), *dstPtr });
        }

        return newRoot;
    }

public:
    BinaryTree() : root(nullptr), height(0), nodeCount(0) {}
    BinaryTree(T* items, int count) : root(nullptr), height(0), nodeCount(0) {
        if (count < 0) {
            throw std::invalid_argument("Размер массива не может быть отрицательным");
        }
        if (!items && count > 0) {
            throw std::invalid_argument("Передан нулевой указатель при ненулевом размере");
        }
        for (int i = 0; i < count; ++i) {
            add(items[i]);
        }
    }
    BinaryTree(const BinaryTree<T>& other) : root(nullptr), height(other.height), nodeCount(other.nodeCount) {
        if (!other.root) return;

        root = copyTree(other.root);
    }
    BinaryTree(const BinaryTree<T>* other) : root(nullptr), height(other->height), nodeCount(other->nodeCount) {
        if (!other->root) return;

        root = copyTree(other->root);
    }
    BinaryTree(const Node* node) : root(nullptr), height(0), nodeCount(0) {
        if (!node) return;

        root = copyTree(node);
        height = node->height;
        nodeCount = countNodes(node);
    }
    BinaryTree(ArraySequence<T>* arr) : root(nullptr), height(0), nodeCount(0) {
        if (!arr) {
            throw std::invalid_argument("Передан нулевой указатель на массив");
        }
        for (int i = 0; i < arr->GetLength(); ++i) {
            add((*arr)[i]);
        }
    }
    BinaryTree(const ArraySequence<T>& arr) : root(nullptr), height(0), nodeCount(0) {
        for (int i = 0; i < arr.GetLength(); ++i) {
            add(arr[i]);
        }
    }
    ~BinaryTree() {
        delete root;
    }

    Node* findNode(const T& item) const {
        if (!root) return nullptr;

        Stack<Node*> stack;
        Node* current = root;

        while (!stack.IsEmpty() || current) {
            while (current) {
                stack.Push(current);
                current = current->left;
            }
            current = stack.Top();
            stack.Pop();

            if (current->value == item) {
                return current;
            }

            current = current->right;
        }
        return nullptr;
    }
    Node* LeftRotate(Node* x) {
        if (!x) {
            throw std::invalid_argument("Нельзя выполнить поворот: узел не существует");
        }
        if (!x->right) {
            throw std::invalid_argument("Нельзя выполнить левый поворот: отсутствует правый потомок");
        }

        Node* y = x->right;
        x->right = y->left;
        if (y->left) {
            y->left->parent = x;
        }
        y->parent = x->parent;

        if (!x->parent) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);
        return y;
    }
    Node* RightRotate(Node* y) {
        if (!y) {
            throw std::invalid_argument("Нельзя выполнить поворот: узел не существует");
        }
        if (!y->left) {
            throw std::invalid_argument("Нельзя выполнить правый поворот: отсутствует левый потомок");
        }

        Node* x = y->left;
        y->left = x->right;
        if (x->right) {
            x->right->parent = y;
        }
        x->parent = y->parent;

        if (!y->parent) {
            root = x;
        }
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;

        updateHeight(y);
        updateHeight(x);
        return x;
    }
    BinaryTree* add(T item) {
        Node* newNode = new Node(item);
        if (!root) {
            root = newNode;
            nodeCount++;
            updateHeight(newNode);
            return this;
        }

        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (current->value == item) return this;
            current = (item < current->value) ? current->left : current->right;
        }

        newNode->parent = parent;
        if (item < parent->value) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
        nodeCount++;

        Node* balanceNode = parent;
        while (balanceNode) {
            updateHeight(balanceNode);
            int balance = getBalanceFactor(balanceNode);

            if (balance > 1) {
                if (getBalanceFactor(balanceNode->left) >= 0) {
                    balanceNode = RightRotate(balanceNode);
                }
                else {
                    balanceNode->left = LeftRotate(balanceNode->left);
                    balanceNode = RightRotate(balanceNode);
                }
            }
            else if (balance < -1) {
                if (getBalanceFactor(balanceNode->right) <= 0) {
                    balanceNode = LeftRotate(balanceNode);
                }
                else {
                    balanceNode->right = RightRotate(balanceNode->right);
                    balanceNode = LeftRotate(balanceNode);
                }
            }

            if (!balanceNode->parent) root = balanceNode;
            balanceNode = balanceNode->parent;
        }

        return this;
    }

    Sequence<T>* LNR() const {
        ArraySequence<T>* result = new ArraySequence<T>;
        if (!result) {
            throw std::runtime_error("Не удалось выделить память для результата обхода");
        }

        if (!root) return result; // Пустое дерево

        Node* current = root;
        Stack<Node*> stack;

        while (!stack.IsEmpty() || current) {
            while (current) {
                stack.Push(current);
                current = current->left;
            }

            current = stack.Top();
            stack.Pop();
            result->Append(current->value);
            current = current->right;
        }

        return result;
    }
    Sequence<T>* RNL() const {
        ArraySequence<T>* result = new ArraySequence<T>;
        if (!result) {
            throw std::runtime_error("Ошибка выделения памяти для результата обхода");
        }
        if (!root) return result;
        Node* current = root;
        Stack<Node*> stack;

        while (!stack.IsEmpty() || current) {
            while (current) {
                stack.Push(current);
                current = current->right;
            }

            current = stack.Top();
            stack.Pop();
            result->Append(current->value);
            current = current->left;
        }

        return result;
    }
    Sequence<T>* NLR() const {
        ArraySequence<T>* result = new ArraySequence<T>;
        if (!result) {
            throw std::runtime_error("Ошибка выделения памяти для результата обхода");
        }

        if (!root) return result;
        Stack<Node*> stack;
        stack.Push(root);

        while (!stack.IsEmpty()) {
            Node* current = stack.Top();
            stack.Pop();

            if (current) {
                result->Append(current->value);
                stack.Push(current->right);
                stack.Push(current->left);
            }
        }

        return result;
    }
    Sequence<T>* NRL() const {
        ArraySequence<T>* result = new ArraySequence<T>;
        if (!result) {
            throw std::runtime_error("Ошибка выделения памяти для результата обхода");
        }

        if (!root) return result; // Пустое дерево

        Stack<Node*> stack;
        stack.Push(root); // Начинаем с корня

        while (!stack.IsEmpty()) {
            Node* current = stack.Top();
            stack.Pop();

            if (current) {
                result->Append(current->value); // Добавляем значение текущего узла
                // Сначала пушим левое поддерево, чтобы обработать его после правого
                stack.Push(current->left);
                stack.Push(current->right); // Правое поддерево обрабатывается первым
            }
        }

        return result;
    }
    Sequence<T>* RLN() const {
        ArraySequence<T>* result = new ArraySequence<T>();
        if (!result) {
            throw std::runtime_error("Ошибка выделения памяти для результата обхода");
        }

        if (!root) return result;

        Stack<Node*> stack;
        Node* current = root;
        Node* lastVisited = nullptr;

        while (!stack.IsEmpty() || current) {
            if (current) {
                stack.Push(current);
                current = current->left;
            }
            else {
                Node* peekNode = stack.Top();
                if (peekNode->right && lastVisited != peekNode->right) {
                    current = peekNode->right;
                }
                else {
                    result->Append(peekNode->value);
                    lastVisited = stack.Top();
                    stack.Pop();
                }
            }
        }

        return result;
    }
    Sequence<T>* LRN() const {
        ArraySequence<T>* result = new ArraySequence<T>();
        if (!result) {
            throw std::runtime_error("Ошибка выделения памяти для результата обхода");
        }

        if (!root) return result;

        Stack<Node*> stack;
        Node* current = root;
        Node* lastVisited = nullptr;

        while (!stack.IsEmpty() || current) {
            if (current) {
                stack.Push(current);
                current = current->right;
            }
            else {
                Node* peekNode = stack.Top();
                if (peekNode->left && lastVisited != peekNode->left) {
                    current = peekNode->left;
                }
                else {
                    result->Append(peekNode->value);
                    lastVisited = stack.Top();
                    stack.Pop();
                }
            }
        }

        return result;
    }

    BinaryTree* remove(T item) {
        Node* current = root;
        Node* parent = nullptr;

        // Поиск узла с заданным значением
        while (current && current->value != item) {
            parent = current;
            current = (item < current->value) ? current->left : current->right;
        }

        if (!current) {
            return this;
        }

        // Случай 1: Удаляемый узел — лист
        if (!current->left && !current->right) {
            if (current == root) {
                root = nullptr;
            }
            else if (parent->left == current) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            delete current;
            nodeCount--;
        }
        // Случай 2: Удаляемый узел имеет одного потомка
        else if (!current->left || !current->right) {
            Node* child = current->left ? current->left : current->right;

            if (current == root) {
                root = child;
                child->parent = nullptr;
            }
            else if (parent->left == current) {
                parent->left = child;
                child->parent = parent;
            }
            else {
                parent->right = child;
                child->parent = parent;
            }

            // Важно: не удаляем детей текущего узла, так как мы их переносим
            current->left = nullptr;
            current->right = nullptr;
            delete current;
            nodeCount--;

            // Обновляем баланс начиная с родителя
            parent = child ? child : parent;
        }
        // Случай 3: Удаляемый узел имеет двух потомков
        else {
            Node* successor = current->right;
            Node* successorParent = current;

            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            current->value = successor->value;

            if (successorParent->left == successor) {
                successorParent->left = successor->right;
                if (successor->right) successor->right->parent = successorParent;
            }
            else {
                successorParent->right = successor->right;
                if (successor->right) successor->right->parent = successorParent;
            }

            // Обновляем баланс начиная с родителя преемника
            parent = successorParent;

            successor->left = nullptr;
            successor->right = nullptr;
            delete successor;
            nodeCount--;
        }

        // Перебалансировка
        Node* balanceNode = parent;
        while (balanceNode) {
            updateHeight(balanceNode);
            int balance = getBalanceFactor(balanceNode);

            // LL
            if (balance > 1 && getBalanceFactor(balanceNode->left) >= 0) {
                if (balanceNode == root) {
                    root = RightRotate(balanceNode);
                    root->parent = nullptr;
                }
                else {
                    Node* gp = balanceNode->parent;
                    if (gp->left == balanceNode) {
                        gp->left = RightRotate(balanceNode);
                        gp->left->parent = gp;
                    }
                    else {
                        gp->right = RightRotate(balanceNode);
                        gp->right->parent = gp;
                    }
                }
            }
            // LR
            else if (balance > 1 && getBalanceFactor(balanceNode->left) < 0) {
                balanceNode->left = LeftRotate(balanceNode->left);
                if (balanceNode->left) balanceNode->left->parent = balanceNode;
                if (balanceNode == root) {
                    root = RightRotate(balanceNode);
                    root->parent = nullptr;
                }
                else {
                    Node* gp = balanceNode->parent;
                    if (gp->left == balanceNode) {
                        gp->left = RightRotate(balanceNode);
                        gp->left->parent = gp;
                    }
                    else {
                        gp->right = RightRotate(balanceNode);
                        gp->right->parent = gp;
                    }
                }
            }
            // RR
            else if (balance < -1 && getBalanceFactor(balanceNode->right) <= 0) {
                if (balanceNode == root) {
                    root = LeftRotate(balanceNode);
                    root->parent = nullptr;
                }
                else {
                    Node* gp = balanceNode->parent;
                    if (gp->left == balanceNode) {
                        gp->left = LeftRotate(balanceNode);
                        gp->left->parent = gp;
                    }
                    else {
                        gp->right = LeftRotate(balanceNode);
                        gp->right->parent = gp;
                    }
                }
            }
            // RL
            else if (balance < -1 && getBalanceFactor(balanceNode->right) > 0) {
                balanceNode->right = RightRotate(balanceNode->right);
                if (balanceNode->right) balanceNode->right->parent = balanceNode;
                if (balanceNode == root) {
                    root = LeftRotate(balanceNode);
                    root->parent = nullptr;
                }
                else {
                    Node* gp = balanceNode->parent;
                    if (gp->left == balanceNode) {
                        gp->left = LeftRotate(balanceNode);
                        gp->left->parent = gp;
                    }
                    else {
                        gp->right = LeftRotate(balanceNode);
                        gp->right->parent = gp;
                    }
                }
            }

            balanceNode = balanceNode->parent;
        }

        return this;
    }
    template <typename U>
    BinaryTree<U>* map(std::function<U(const T&)> func) const {
        if (!func) {
            throw std::invalid_argument("Null function pointer passed to map");
        }
        BinaryTree<U>* result = new BinaryTree<U>();
        if (!root) return result;

        Sequence<T>* source = this->LNR();
        ArraySequence<T>* arrSeq = dynamic_cast<ArraySequence<T>*>(source);

        if (arrSeq) {
            for (int i = 0; i < arrSeq->GetLength(); ++i) {
                result->add(func(arrSeq->Get(i)));
            }
        }

        delete source;
        return result;
    }
    BinaryTree<T>* where(std::function<bool(const T&)> predicate) const {
        if (!predicate) {
            throw std::invalid_argument("Null predicate pointer passed to where");
        }
        BinaryTree<T>* result = new BinaryTree<T>();
        if (!result) {
            throw std::runtime_error("Memory allocation failed for new tree");
        }
        // Use LNR traversal to get elements in order
        Sequence<T>* seq = LNR();
        if (!seq) {
            delete result;
            throw std::runtime_error("Failed to get traversal sequence");
        }
        // Insert elements that satisfy the predicate
        for (int i = 0; i < seq->GetLength(); ++i) {
            T value = (*dynamic_cast<ArraySequence<T>*>(seq))[i];
            if (predicate(value)) {
                result->add(value);
            }
        }
        delete seq;
        return result;
    }
    BinaryTree<T>* extractSubtree(const T& item) const {
        Node* subtreeRoot = findNode(item); 
        if (!subtreeRoot) return nullptr;

        Node* copiedSubtree = copyTree(subtreeRoot);
        return new BinaryTree<T>(copiedSubtree);
    }
    bool containsSubtree(const BinaryTree<T>& subtree) const {
        if (subtree.isEmpty()) return true;
        const Node* subRoot = subtree.getRoot();
        if (!subRoot) return true;
        if (!root) return false;

        Stack<const Node*> stack;
        stack.Push(root);

        while (!stack.IsEmpty()) {
            const Node* current = stack.Top();
            stack.Pop();
            if (current->value == subRoot->value) {
                if (compareSubtrees(current, subRoot)) {
                    return true;
                }
            }

            if (current->right) stack.Push(current->right);
            if (current->left) stack.Push(current->left);
        }
        return false;
    }
    bool compareSubtrees(const Node* a, const Node* b) const { // для понимания нода a - это корень дерева (поддерева исходного дерева)
        //а нода b - нода, являющаяся корнем дерева, которое проверяется на вхождение как поддерево в дерево A
        Stack<const Node*> stackA;
        Stack<const Node*> stackB;

        stackA.Push(a);
        stackB.Push(b);

        while (!stackA.IsEmpty() && !stackB.IsEmpty()) {
            const Node* nodeA = stackA.Top();
            const Node* nodeB = stackB.Top();
            stackA.Pop();
            stackB.Pop();

            if (!nodeA && !nodeB) continue;

            if (!nodeA || !nodeB) return false;

            if (nodeA->value != nodeB->value) return false;
            if (!(nodeB->left || nodeB->right)) continue;
            stackA.Push(nodeA->right);
            stackA.Push(nodeA->left);

            stackB.Push(nodeB->right);
            stackB.Push(nodeB->left);
        }

        return stackA.IsEmpty() && stackB.IsEmpty();
    }
    bool contains(T item) const {
        Node* current = root;
        while (current) {
            if (current->value == item) {
                return true;
            }
            else if (current->value > item) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    int getHeight() const {
        return root ? root->height : 0;
    }
    T Reduce(std::function<T(const T&, const T&)> func, const T& initial) const {
        if (!func) {
            throw std::invalid_argument("Null function pointer passed to reduce");
        }

        if (!root) {
            return initial;
        }

        Sequence<T>* seq = LNR();
        if (!seq) {
            throw std::runtime_error("Failed to get traversal sequence");
        }

        T result = initial;
        ArraySequence<T>* arrSeq = dynamic_cast<ArraySequence<T>*>(seq);
        if (!arrSeq) {
            delete seq;
            throw std::runtime_error("Failed to cast Sequence to ArraySequence");
        }

        for (int i = 0; i < arrSeq->GetLength(); ++i) {
            result = func(result, (*arrSeq)[i]);
        }

        delete seq;
        return result;
    }
    Node* getRoot() const {
        return root;
    }
    int getNodeCount() const {
        return nodeCount;
    }
    bool isEmpty() const {
        return root == nullptr;
    }
    void printTree(Node* node, int depth = 0) const {
        if (!node) return;
        for (int i = 0; i < depth; ++i) std::cout << "  ";

        std::cout << node->value << " (height: " << node->height
            << ", parent: " << (node->parent ? node->parent->value : -1)
            << ", left: " << (node->left ? node->left->value : -1)
            << ", right: " << (node->right ? node->right->value : -1) << ")\n";
        printTree(node->left, depth + 1);
        printTree(node->right, depth + 1);
    }
    void printTree() const {
        std::cout << "Структура дерева:\n";
        if (!root) std::cout << "Дерево пусто\n";
        else printTree(root);
    }
    bool operator==(const BinaryTree<T>& other) const {
        Stack<const Node*> stack1, stack2;
        const Node* curr1 = root;
        const Node* curr2 = other.root;

        while (!stack1.IsEmpty() || curr1 || !stack2.IsEmpty() || curr2) {
            while (curr1 || curr2) {
                if ((curr1 && !curr2) || (!curr1 && curr2)) {
                    return false;
                }
                if (curr1 && curr2 && curr1->value != curr2->value) {
                    return false;
                }
                if (curr1) {
                    stack1.Push(curr1);
                    curr1 = curr1->left;
                }
                if (curr2) {
                    stack2.Push(curr2);
                    curr2 = curr2->left;
                }
            }
            if (stack1.GetCount() != stack2.GetCount()) {
                return false;
            }
            if (stack1.IsEmpty() && stack2.IsEmpty()) {
                break;
            }
            curr1 = stack1.Top()->right;
            curr2 = stack2.Top()->right;
            stack1.Pop();
            stack2.Pop();
        }
        return stack1.IsEmpty() && stack2.IsEmpty();
    }
};