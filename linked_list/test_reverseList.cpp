#include "leetcode.hpp"

void test_reverseList() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy(-1);
  gen_list(n, &dummy);
  print_list(dummy.next,"Original");
  ListNode* r = reverseList(dummy.next);
  print_list(r,"Reverse");
  print_list(reverseList_recursive(r), "Reverse");
}
