#include "leetcode.hpp"

void test_sortedArrayToBST() {
  srand((unsigned int)time(NULL));
  int n = rand()%20;
  vector<int> nums;
  gen_array(n, nums);
  sort(nums.begin(), nums.end());
  print_array(nums);

  TreeNode *root = sortedArrayToBST(nums);

  vector<vector<int> > r = levelOrder(root);
  cout << "level order = " << endl;
  for(int i = 0; i < r.size(); ++i) {
    for(auto j : r[i])
      cout << j << "\t";
    cout << endl;
  }
}
