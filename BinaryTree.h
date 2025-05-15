#pragma once
#include <iostream>
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
		Node() :value(T()), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
		Node(T item) :value(item), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
		Node(T item, Node* parent) :value(item), left(nullptr), right(nullptr), parent(parent), height(0) {}
		~Node() {
			if (left) delete left;
			if (right) delete right;
		}
	};
	Node* root;
	int height;
	int nodeCount;
public:
	BinaryTree() : root(nullptr), height(0) {}
	BinaryTree(T* m, int count) : root(nullptr), height(0) {
		for (int i = 0; i < count; ++i) {
			add(m[i]);
		}
	}
	BinaryTree(ArraySequence<T>* arr) {
		for (int i = 0; i < arr->GetLength(); ++i) {
			add((*arr)[i]);
		}
	}
	BinaryTree(const ArraySequence<T>& arr) {
		for (int i = 0; i < arr.GetLength(); ++i) {
			add(arr[i]);
		}
	}
	Node* LeftRotate() {

	}
	Node* RightRotate() {

	}
	~BinaryTree() {
		delete root;
	}

	BinaryTree* add(T item) {
		if (!root) {
			root = new Node(item);
			return this;
		}
		Node* tmp = root;
		Node* preTmp = nullptr;
		while (tmp) {
			preTmp = tmp;
			if (tmp->value > item) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
		if (preTmp->value > item) {
			preTmp->left = new Node(item, preTmp);
		}
		else {
			preTmp->right = new Node(item, preTmp);
		}
		nodeCount++;

		return this;
	}
	ArraySequence<T>* LNR() {
		ArraySequence<T>* result = new ArraySequence<T>;
		Node* current = root;
		Stack<Node*> stack;
		while (!stack.Is_empty() || current) {
			while (current) {
				stack.Add(current);
				current = current->left;
			}
			current = stack.Top();
			stack.Pop();
			result->Append(current->value);
			current = current->right;
		}
		return result;
	}
	ArraySequence<T>* RNL() {
		ArraySequence<T>* result = new ArraySequence<T>;
		Node* current = root;
		Stack<Node*> stack;
		while (!stack.Is_empty() || current) {
			while (current) {
				stack.Add(current);
				current = current->right;
			}
			current = stack.Top();
			stack.Pop();
			result->Append(current->value);
			current = current->left;
		}
		return result;
	}
	ArraySequence<T>* NLR() {
		ArraySequence<T>* result = new ArraySequence<T>;
		Node* current = root;
		Stack<Node*> stack;
		while (!stack.Is_empty() || current) {
			while (current) {
				stack.Add(current);
				result->Append(current->value);
				current = current->left;
			}
			current = stack.Top();
			stack.Pop();
			current = current->right;
		}
		return result;
	}
	ArraySequence<T>* NRl() {
		ArraySequence<T>* result = new ArraySequence<T>;
		Node* current = root;
		Stack<Node*> stack;
		while (!stack.Is_empty() || current) {
			while (current) {
				stack.Add(current);
				result->Append(current->value);
				current = current->right;
			}
			current = stack.Top();
			stack.Pop();
			current = current->left;
		}
		return result;
	}
	/*ArraySequence<T>* LRN() {
		ArraySequence<T>* result = new ArraySequence<T>;
		Node* current = root;
		Stack<Node*> stack;
		while (!stack.Is_empty() || current) {
			while (current) {
				stack.Add(current);
				current = current->left;
				if(!current->left){
					current = stack.Top();
					stack.Pop();
					while (current) {
						stack.Add(current);
						current = current->right;
					}
				}
			}
			current = stack.Top();
			stack.Pop();

			current = stack.Top();
			stack.Pop();
			result->Append(current->value);
		}
		return result;
	}*/
	ArraySequence<T>* LRN() {
		ArraySequence<T>* result = new ArraySequence<T>();
		Stack<Node*> stack;
		Node* current = root;
		Node* last = nullptr;
		while (!stack.Is_empty()||current) {
			std::cout << "hhhhh";
			if (current && (last != current->left)) {
				stack.Add(current);
				current = current->left;
			}
			else if (!stack.Top()->right || last == stack.Top()->right) {
				current = stack.Top();
				last = current;
				result->Append((stack.Pop())->value);
			}
			else{
				current = current->right;
			}
			/*current = stack.Top();
			if (current->right) {
				current = current->right;
			}
			else {
				result->Append((stack.Pop())->value);
				current = stack.Top();
			}
		}*/
			
		}
		return result;
	}
};
