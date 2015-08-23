#include "leetcode.hpp"

void test_reorderList() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy;
  gen_list(n, &dummy, true);
  print_list(dummy.next, "Original");
  reorderList(dummy.next);
  print_list(dummy.next, "Reorder");
}
