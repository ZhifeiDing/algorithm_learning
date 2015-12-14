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

// segment tree solution
struct SegmentTreeNode {
  
};

vector<int> countSmaller(vector<int> &nums) {
}


// insertion sort solution
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
