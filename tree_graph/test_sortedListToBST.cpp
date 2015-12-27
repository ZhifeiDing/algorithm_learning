#include "leetcode.hpp"

void test_sortedListToBST() {
  srand((unsigned int)time(NULL));
  int n = rand()%20;
  ListNode dummy(-1);
  gen_list(n, &dummy, true);
  print_list(dummy.next, "List =");
  TreeNode *root = sortedListToBST(dummy.next);

  vector<vector<int> > r = levelOrder(root);
  cout << "level order = " << endl;
  for(int i = 0; i < r.size(); ++i) {
    for(auto j : r[i])
      cout << j << "\t";
    cout << endl;
  }

  root = sortedListToBST(dummy.next);

  r = levelOrder(root);
  cout << "level order = " << endl;
  for(int i = 0; i < r.size(); ++i) {
    for(auto j : r[i])
      cout << j << "\t";
    cout << endl;
  }
}
