#include "leetcode.hpp"

/*
 * A linked list is given such that each node contains an additional random pointer which 
 * could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 *
 */

RandomListNode *copyRandomList(RandomListNode *head) {
  RandomListNode dummy(-1);
  RandomListNode *p = &dummy;
  unordered_map<RandomListNode*, RandomListNode*> listMap;
  listMap[NULL] = NULL;

  while( head ) {
    RandomListNode *cur,*random;
    if( listMap.find(head) == listMap.end() ) {
      cur = new RandomListNode(head->label);
      listMap[head] = cur;
    }
    /*
    if( head->next && listMap.find(head->next) == listMap.end() ) {
      next = new RandomListNode(head->next->label);
      listMap[head] = next;
    }
    */
    if( head->random && listMap.find(head->random) == listMap.end() ) {
      random = new RandomListNode(head->random->label);
      listMap[head->random] = random;
    }

    cur = listMap[head];
    //next = listMap[head->next];
    random = listMap[head->random];
    p->next= cur;
    //p->next->next = next;
    p->next->random = random;

    head = head->next;
    p = p->next;
  }

  return dummy.next;
}
