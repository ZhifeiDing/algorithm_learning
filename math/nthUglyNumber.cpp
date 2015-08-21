#include "leetcode.hpp"

/*
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only 
 * include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 
 * is the sequence of the first 10 ugly numbers.
 * 
 * Note that 1 is typically treated as an ugly number.
 * 
 * Hint:
 * 
 * The naive approach is to call isUgly for every number until you 
 * reach the nth one. Most numbers are not ugly. Try to focus your 
 * effort on generating only the ugly ones.
 * An ugly number must be multiplied by either 2, 3, or 5 from a smaller 
 * ugly number.
 * The key is how to maintain the order of the ugly numbers. Try a 
 * similar approach of merging from three sorted lists: L1, L2, and L3.
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be 
 * Min(L1 * 2, L2 * 3, L3 * 5).
 */

int nthUglyNumber(int n) {
  if( n == 1 )
    return n;
  vector<int> v2(n,0), v3(n,0), v5(n,0);
  int i = 1, a = 0, b = 0, c = 0;
  v2[0] = 2;
  v3[0] = 3;
  v5[0] = 5;

  int ret;

  while( i < n ) {
    ret = min(v2[a], min(v3[b], v5[c]));
    v2[i] = ret * 2;
    v3[i] = ret * 3;
    v5[i] = ret * 5;

    if( ret == v2[a] )
      ++a;
    if( ret == v3[b] )
      ++b;
    if( ret == v5[c] )
      ++c;
    ++i;
  }
  return ret;
}

int nthUglyNumber_set(int n) {
    set<long> nums;
    nums.insert(1);
    int i = 0;
    long ret;
    while( i < n ) {
        auto itr = nums.begin();
        ret = *itr;
        nums.erase(itr);
        nums.insert(ret * 2);
        nums.insert(ret * 3);
        nums.insert(ret * 5);
        
        i++;
    }
    return ret;
}
