#include "leetcode.hpp"

/*
 * Write a program to find the nth super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors 
 * are in the given prime list primes of size k. For example, 
 * [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the 
 * first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 * 
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 */

int nthSuperUglyNumber(int n,  vector<int> & primes) {
  set<long> ugly;
  ugly.insert(1);

  int i = 1;
  int ret = 1;

  while( i <= n ) {
    auto itr = ugly.begin();
    ret = *itr;
    ugly.erase(itr);

    for(auto i : primes)
      ugly.insert(ret * i);
    ++i;
  }
  return ret;
}

int nthSuperUglyNumber_dp(int n,  vector<int> & primes) {
  vector<int> idx(primes.size(),0);
  vector<long> ugly;

  ugly.push_back(1);

  int i = 1;
  while( i < n ) {
    vector<int> pos;
    long minUgly = INT_MAX;
    for(int j = 0; j < primes.size(); ++j) {
      //minUgly = min(minUgly, ugly[idx[j]] * primes[j]);
      if( minUgly > ugly[idx[j]] * primes[j] ) {
        minUgly = ugly[idx[j]] * primes[j];
        pos.resize(0);
        pos.push_back(j);
      } else if( minUgly == ugly[idx[j]] * primes[j] ) {
        pos.push_back(j);
      }
    }
    ugly.push_back(minUgly);
    for(auto j : pos)
      ++idx[j];
    ++i;
  }

  return ugly[n-1];
}
