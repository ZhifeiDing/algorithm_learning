#include "leetcode.hpp"

/*
 * Find the kth largest element in an unsorted array. Note that it is the 
 * kth largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */
int partition(vector<int> & nums, int start, int end) {
  int mid = ( start + end ) / 2;
  int pivot = nums[mid];
  swap(nums[mid], nums[start]);
  while( start < end ) {
    while( start < end && pivot <= nums[end] ) end--;
    if( start < end )
      nums[start++] = nums[end];
    while( start < end && nums[start] < pivot ) start++;
    if( start < end )
      nums[end--] = nums[start];
  }
  nums[start] = pivot;
  return start;
}

int findKthLargest(vector<int> & nums, int k) {
  int start = 0, end = nums.size() - 1;
  int idx = partition(nums, start, end);
  while( nums.size() - k != idx ) {
    if( nums.size() -k < idx ) {
      end = idx - 1;
      idx = partition(nums, start, end);
    } else {
      start = idx + 1;
      idx = partition(nums, start, end);
    }
  }
  return nums[idx];
}

void adjustHeap(vector<int> & nums, int n, int size) {
  int nchild = 2 * n + 1;
  while( nchild < size ) {
    if( nchild + 1 < size && nums[nchild+1] < nums[nchild] )
      nchild++;
    if( nums[n] < nums[nchild] )
      break;
    swap(nums[n], nums[nchild]);
    n = nchild;
    nchild = 2*n + 1;
  }
}

int findKthLargest_minHeap(vector<int> & nums, int k) {
  for(int i = k/2 - 1; i >= 0; i--)
    adjustHeap(nums, i, k);
  for(int i = k; i < nums.size(); i++) {
    if( nums[i] > nums[0] ) {
      nums[0] = nums[i];
      adjustHeap(nums, 0, k);
    }
  }
  return nums[0];
}
