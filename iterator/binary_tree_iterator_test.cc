#include "public/binary_tree_iterator.h"

#include <string>

#include "gtest/gtest.h"

namespace {
using std::cout;
using std::string;

using std::endl;

class Iterator : public ::testing::Test {
 protected:
  //         me
  //        /  \
  //   mother   father
  //      / \
  //   m'm   m'f

  BinaryTree<string> family_ = BinaryTree<string>(
      new Node<string>{"me",
                       new Node<string>{"mother",
                                        new Node<string>{"mother's mother"},
                                        new Node<string>{"mother's father"}},
                       new Node<string>{"father"}});
};

TEST_F(Iterator, BinaryTreeInOrderIterator) {
  for (auto it = family_.begin(); it != family_.end(); ++it) {
    cout << (*it).value << endl;
  }
}

TEST_F(Iterator, BinaryTreeInOrder) {
    for (const auto& it: family_.pre_order) {
        cout << it.value << endl;
    }
}

}  // namespace