#include "leetcode.hpp"
/*
 *
 *Given a positive integer n, break it into the sum of at least two
 *positive integers and maximize the product of those integers. Return
 *the maximum product you can get.
 *
 *For example, given n = 2, return 1 (2 = 1 + 1); given n = 10,
 *    return 36 (10 = 3 + 3 + 4).
 *
 *Note: you may assume that n is not less than 2.
 *
 *Hint:
 *
 *There is a simple O(n) solution to this problem.
 *You may check the breaking results of n ranging from 7 to 10 to discover
 *the regularities.
 */

int integerBreak(int n) {
    // we can apply math technology to solve the problem
    if( n == 2 )
        return 1;
    else if( n == 3 )
        return 2;
    else if( n%3 == 0 )
        return pow(3,n/3);
    else if( n%3 == 1 )
        return 4 * pow(3,(n-4)/3);
    else
        return 2 * pow(3,(n-2)/3);
}

int integerBreak_DP(int n) {
    // just split the problem to two subproblem
    // f[i] = max(f[i], max(j,f[j]) * max(i-j, f[i-j]))
    vector<int> f(n+1);
    f[1] = 1;
    for(int i = 2; i <= n; ++i)
        for(int j = 1; 2 * j <= i; ++j)
            f[i] = max(f[i], max(j, f[j]) * max(i-j, f[i-j]));
    return f[n];
}