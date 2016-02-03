#include "leetcode.hpp"

void test_removeNthFromEnd(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy(-1);
  gen_list(n,&dummy,false);
  print_list(dummy.next, "Original List");
  int val = (n == 0) ? 0 : rand()%n + 1;
  ListNode* p = removeNthFromEnd(dummy.next,val);
  cout << "n = " << val << endl;
  print_list(p, "After remove: ");
}
