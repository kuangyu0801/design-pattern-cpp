#pragma once

#include <vector>

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder_traversal(std::vector<Node<T>*>& result)
    {
        preorder(this, result);
    }
    
    static void preorder(Node* cur, std::vector<Node<T>*>& result) {
        if (cur == nullptr) {
            return;
        }
        
        result.push_back(cur);
        preorder(cur->left, result);
        preorder(cur->right, result);
    }
};