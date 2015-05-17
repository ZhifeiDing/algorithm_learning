#include "leetcode.hpp"

void test_removeElements(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy(-1);
  gen_list(n,&dummy,false);
  print_list(dummy.next, "Original List");
  int val = rand()%9;
  ListNode* p = removeElements(dummy.next,val);
  cout << "val = " << val << endl;
  print_list(p, "After remove: ");
}
