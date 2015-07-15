#include "leetcode.hpp"

void test_deleteNode() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy;
  gen_list(n, &dummy, true);
  print_list(dummy.next, "Original");
  int k = rand()%n;
  ListNode* node = dummy.next;
  while( k-- > 0 )
    node = node->next;
  deleteNode(node);
  cout << "remove " << node->val << endl;
  print_list(dummy.next,"Remove Duplicates");
}
