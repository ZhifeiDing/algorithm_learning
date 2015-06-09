#include "leetcode.hpp"

void test_deleteDuplicates() {
  srand((unsigned int)time(NULL));
  int n = rand()%11;
  ListNode dummy;
  gen_list(n, &dummy, true);
  print_list(dummy.next, "Original");
  ListNode* r = deleteDuplicates(dummy.next);
  print_list(r,"Remove Duplicates");
}

