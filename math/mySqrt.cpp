#include "leetcode.hpp"

/*
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */

int mySqrt(int x) {
  int l = 0, r = x/2;
  while( l <= r ) {
    long long int i = ( r - l ) / 2 + l;
    if( x < i * i )
      r = i;
    else if( x < ( i + 1 ) * ( i+ 1 ) && i * i <= x )
      return i;
    else
      l = i + 1;
  }
  return l;
}
