#include "leetcode.hpp"

bool isPrime(int n) {
  for(int i = 2; i <= sqrt(double(n)); ++i)
    if( n % i == 0 )
      return false;
  return true;
}

void genPrimes(vector<int> &primes, int n) {
  int i = 0; 
  int p = 2;
  while( i < n ) {
    while( isPrime(p) == false )
      ++p;
    primes.push_back(p);
    ++p;
    ++i;
  }
}

void test_nthSuperUglyNumber() {
  srand((unsigned int)time(NULL));
  int n = rand()%20 + 1;
  vector<int> primes;
  int m = rand()%10 + 1;
  genPrimes(primes, m);
  cout << "primes = ";
  print_array(primes);
  int r = nthSuperUglyNumber(n, primes);
  cout << n << "th ugly number = " << r << endl;
  cout << n << "th ugly number = " << nthSuperUglyNumber_dp(n, primes) << endl;
}
