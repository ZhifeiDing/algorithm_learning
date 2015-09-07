#include "leetcode.hpp"

/*
 * Implement pow(x, n).
 */
double myPow(double x, int n) {
    if( x == 1.0 )
        return x;
    if( n < 0 )
      if( n == INT_MIN )
        return 1 / ( x * myPow(x, INT_MAX));
      return 1 / myPow(x, int(0-n));
    if( n == 0 )
        return 1;
    if( n == 1 )
        return x;

    double x2 = myPow(x, n/2);
    return n%2 ? x2 * x2 * x : x2 * x2;
}
