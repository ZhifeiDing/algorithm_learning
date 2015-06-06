#include "leetcode.hpp"

void test_copyRandomList(void) {
  RandomListNode head(1);
  RandomListNode next1(2);
  RandomListNode random1(3);
  RandomListNode nextnext(4);
  RandomListNode nextRandom(5);
  head.next = &next1;
  head.random = &random1;
  next1.next = &nextnext;
  next1.random = &nextRandom;

  RandomListNode* r = copyRandomList(&head);
}
