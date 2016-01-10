#include "leetcode.hpp"

void test_generateTrees() {
  int n = 3;
  vector<TreeNode*> r = generateTrees(n);
  for(auto i : r) {
    print_tree(i);
  }
}
