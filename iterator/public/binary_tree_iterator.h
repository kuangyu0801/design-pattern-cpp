#pragma once

#include <experimental/coroutine>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
// #include <experimental/generator>

// forward declaration
template <typename T>
struct BinaryTree;

// todo: refactor to refer to parent instead of entire tree
template <typename T>
struct Node {
  T value = T();
  Node<T>* left = nullptr;
  Node<T>* right = nullptr;
  Node<T>* parent = nullptr;
  BinaryTree<T>* tree = nullptr;

  explicit Node(const T& value) : value(value) {}

  Node(const T& value, Node<T>* const left, Node<T>* const right)
      : value(value), left(left), right(right) {
    this->left->tree = tree;
    this->right->tree = tree;
    this->left->parent = this;
    this->right->parent = this;
  }

  void set_tree(BinaryTree<T>* t) {
    tree = t;
    if (left) {
      left->set_tree(t);
    }
    if (right) {
      right->set_tree(t);
    }
  }

  ~Node() {
    if (left) {
      delete left;
    }
    if (right) {
      delete right;
    }
  }
};

template <typename T>
struct BinaryTree {
  explicit BinaryTree(Node<T>* const root) : root{root}, pre_order{*this} {
    root->set_tree(this);
  }

  ~BinaryTree() {
    if (root)
      delete root;
  }

  // Iterator class for BinaryTree
  // This is reference from: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
  // I doubt there is preorder without recursion without stack.
  template <typename U>
  struct InOrderIterator {
    // Current position
    Node<U>* current;

    explicit InOrderIterator(Node<U>* current) : current(current) {}

    bool operator!=(const InOrderIterator<U>& other) {
      return current != other.current;
    }

    // Implementation for node traversal.
    // no continuations in C++ (unlike C#)
    InOrderIterator<U>& operator++() {
      // Implements in a non-recursive way because operator++() doesn't take
      // any parameter.
      if (current->right) {
        current = current->right;
        while (current->left) {
          current = current->left;
        }
      } else {
        Node<T>* p = current->parent;
        while (p && current == p->right) {
          current = p;
          p = p->parent;
        }
        current = p;
      }
      return *this;
    }

    // Returns current position
    Node<U>& operator*() { return *current; }
  };

  using Iterator = InOrderIterator<T>;
  //typedef InOrderIterator<T> Iterator;
  Iterator end() { return Iterator{nullptr}; }
  Iterator begin() {
    Node<T>* n = root;

    if (n) {
      while (n->left) {
        n = n->left;
      }
    }
    return Iterator{n};
  }

  // expose as a traversal object
  // todo: make this inorder
  class PreOrderTraversal {
   public:
    PreOrderTraversal(BinaryTree<T>& tree) : tree_{tree} {}
    Iterator begin() { return tree_.begin(); }
    Iterator end() { return tree_.end(); }
    // TODO: enable when boost is available:
    //     experimental::generator<Node<T>*> post_order() {
    //       return post_order_impl(root);
    //     }

    //    private:
    //     // or use a recursive_generator
    //     experimental::generator<Node<T>*> post_order_impl(Node<T>* node) {
    //       if (node) {
    //         for (auto x : post_order_impl(node->left))
    //           co_yield x;
    //         for (auto y : post_order_impl(node->right))
    //           co_yield y;
    //         co_yield node;
    //       }
    //     }

    BinaryTree<T>& tree_;

  };

  PreOrderTraversal pre_order;
  Node<T>* root = nullptr;
};