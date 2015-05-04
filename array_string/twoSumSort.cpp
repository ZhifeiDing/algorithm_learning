#include "leetcode.hpp"
/*
 * Similar to Question [1. Two Sum], except that the input array is 
 * already sorted in ascending order. Solution:  Of course we could 
 * still apply the [Hash table] approach, but it costs us O(n) extra 
 * space, plus it does not make use of the fact that the input is 
 * already sorted. 
 * O(n log n) runtime, O(1) space – Binary search:  
 * For each element x, we could look up if target – x exists in O(log n) 
 * time by applying binary search over the sorted array. Total runtime 
 * complexity is O(n log n).
 */
vector<int> twoSumSort_binarySearch(vector<int> & numbers, int target) {
  for(int i = 0; i < numbers.size()-1; i++) {
    int j = binarySearch(numbers, target - numbers[i], i+1);
    if( j != -1 ) {
      return vector<int> {i+1, j+1};
    }
  }
  return vector<int> {-1,-1};
}

int binarySearch(vector<int> & numbers, int key, int start) {
  int L = start, R = numbers.size() - 1;
  while( L < R ) {
    int M = ( L + R ) / 2;
    if( numbers[M] > key )
      R = M;
    else if( key > numbers[M] )
      L = M + 1;
    else
      return M;
  }
  return (L == R && numbers[L] == key) ? L:-1;
}

/*
 * O(n) runtime, O(1) space – Two pointers:  
 * Let’s assume we have two indices pointing to the ith and jth elements, Ai 
 * and Aj  respectively. The sum of Ai and Aj could only fall into one of these 
 * three possibilities: 
 *  i.    Ai + Aj > target. Increasing i isn’t going to help us, 
 * as it makes the sum even bigger. Therefore we should decrement j.  
 *  ii.   Ai + Aj < target. Decreasing j isn’t going to help us, as it makes the sum even 
 * smaller. Therefore we should increment i. 
 *  iii.  Ai + Aj == target. We have found the answer.
 */
vector<int> twoSumSort_twoPointer(vector<int> & numbers, int target) {
  int l = 0, r = numbers.size() - 1;
  while( l < r ) {
    if( numbers[l] + numbers[r] > target )
      r--;
    else if( target > numbers[l] + numbers[r] )
      l++;
    else
      return vector<int> {l+1,r+1};
  }
  return vector<int> {-1,-1};
}
