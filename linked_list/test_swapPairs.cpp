#include "leetcode.hpp"

void test_swapPairs(void) {
  srand((unsigned int)time(NULL));
  int n = rand()%10;
  ListNode l(0,NULL);
  ListNode* p = &l;
  gen_list(n,p);
  print_list(l.next);

  p = swapPairs(l.next);
  print_list(p);
}

