#include "leetcode.hpp"

void test_findMissingRanges(void) {
  vector<int> vars;
  srand((unsigned int)time(NULL));
  int n = rand() % 97;
  gen_array(n, vars);
  sort(vars.begin(),vars.end());
  cout << "Original vector: ";
  print_array(vars);
  cout << "Missing Ranges : ";
  list<string> r = findMissingRanges(vars, 0, 99);
  for( auto itr : r ) 
    print_string(itr);
}
