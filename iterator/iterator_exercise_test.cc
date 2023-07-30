#include "public/iterator_exercise.h"

#include <iostream>

#include "gtest/gtest.h"

using std::ostringstream;
using std::vector;

TEST(Iterator, ExampleTest) {
  //        a
  //       /  \
  //      b    e
  //     / \
  //    c   d
  Node<char> c{'c'};
  Node<char> d{'d'};
  Node<char> e{'e'};
  Node<char> b{'b', &c, &d};
  Node<char> a{'a', &b, &e};

  vector<Node<char>*> result;
  a.preorder_traversal(result);

  ostringstream oss;
  for (auto n : result) {
    oss << n->value;
  }
  ASSERT_EQ("abcde", oss.str());
}