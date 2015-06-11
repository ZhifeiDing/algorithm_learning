#include "leetcode.hpp"

void test_findRepeatedDnaSequences() {
  //string s = "AAGGGTTTAAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> r = findRepeatedDnaSequences(s);
  for(int i = 0; i < r.size(); i++)
    cout << r[i] << endl;
}
