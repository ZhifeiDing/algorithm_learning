#include "leetcode.hpp"

void test_mergeKLists() {
  srand((unsigned int)time(NULL));
  int k = rand()%7;
  vector<ListNode*> lists;
  for(int i = 0; i < k; i++) {
    ListNode dummy(-1);
    int n = rand()%9;
    gen_list(n, &dummy, true);
    print_list(dummy.next, "List");
    lists.push_back(dummy.next);
  }
  ListNode* t = mergeKLists_heap(lists);
  print_list(t, "Merged");
  //ListNode* r = mergeKLists(lists);
  //print_list(r, "Merged");
}
