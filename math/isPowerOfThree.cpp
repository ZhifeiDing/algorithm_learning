#include "leetcode.hpp"

/*
 * Given an integer, write a function to determine if it is a power of three.
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 */

bool isPowerOfThree(int n) {
  if( n < 3 )
    return false;
  double num = log10(n)/log10(3);
  return int(num) == num;
}
