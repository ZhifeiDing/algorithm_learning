#include "leetcode.hpp"

/*
 * Count the number of prime numbers less than a non-negative number, n.
 */
int countPrimes(int n) {
  vector<int> primes(n,true);
  primes[0] = false;
  primes[1] = false;
  for(int i = 2; i < sqrt(n)+1; i++) {
    if( primes[i] ) {
      int j = i;
      while( j * i < n ) {
        primes[i*j] = false;
        j++;
      }
    }
  }
  return count(primes.begin(), primes.end(),true);
}

