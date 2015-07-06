#include "leetcode.hpp"
/*
 * Given an integer, write a function to determine if it is a power of two.
 */

bool isPowerOfTwo(int n) {
    int cnt = 0;
    if( n < 0 )
        return false;
    while( n && cnt < 3 ) {
        if( n & 1 )
            cnt++;
        n = n >> 1;
    }
    return cnt == 1;
}

bool isPowerOfTwo_online(int n) {
  return n > 0 && !( n & (n - 1) );
}

