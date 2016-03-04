#include "leetcode.hpp"

/*
 * You are given an integer array nums and you have to return a
 * new counts array. The counts array has the property where counts[i]
 * is the number of smaller elements to the right of nums[i].
 *
 * Example:
 *
 * Given nums = [5, 2, 6, 1]
 *
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * Return the array [2, 1, 1, 0].
 */


// BST solution
struct Node {
  int val;
  int count;
  Node *left;
  Node *right;
  Node(int v, int c) : val(v), count(c), left(NULL), right(NULL) {}
};

int updateBST(int num, Node *node, int cnt) {
  ++node->count;
  if( node->val == num ) {
    return node->count;
  } else if( node->val > num ) {
    if( node->left == NULL )
      node->left = new Node(num, cnt-1);
    return updateBST(num, node->left, cnt);
  } else {
    if( node->right == NULL )
      node->right = new Node(num, node->count + cnt);
    return updateBST(num, node->right, node->count);
  }
}

vector<int> countSmaller_BST(vector<int> &nums) {
  vector<int> r(nums.size(), 0);
  if( nums.size() < 2 )
    return r;
  Node *root = new Node(nums.back(),0);
  for(int i = nums.size()-2; i >= 0; --i)
    r[i] = updateBST(nums[i], root, 0);
  return r;
}

// insertion sort solution
// O(n^2)
void insertSort(int num, vector<int> &r, vector<int> &sortNums, int idx) {
  int pos = distance(sortNums.begin(),lower_bound(sortNums.begin(), sortNums.end(), num));
  sortNums.insert(sortNums.begin() + pos, num);
  r[idx] =  pos;
}

vector<int> countSmaller_insertSort(vector<int> &nums) {
  vector<int> r(nums.size(),0);
  vector<int> sortNums;

  for(int i = nums.size() - 1; i >= 0; --i)
    insertSort(nums[i], r, sortNums, i);
  return r;
}
