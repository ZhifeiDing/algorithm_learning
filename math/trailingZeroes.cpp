#include "leetcode.hpp"
/*
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 */

int trailingZeroes(int n) {
     int r = 0;
     do {
         r += n/5;
     } while( n = n/5 );

     return r;
}
