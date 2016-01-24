#include "leetcode.hpp"

void test_longestConsecutive() {
    TreeNode r3(5);
    TreeNode r2(4,NULL,&r3);
    TreeNode l2(2);
    TreeNode r1(3,&l2,&r2);
    TreeNode root(1,NULL,&r1);

    print_tree(&root);

    cout << "Longest consecutive sequence = " << longestConsecutive(&root) << endl;
}
