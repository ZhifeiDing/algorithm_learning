#include "leetcode.hpp"

void test_anagrams() {
  srand((unsigned int)time(NULL));
  int n = rand()%9+1;
  int k = rand()%9;
  vector<string> strs;
  for(int i = 0; i < n; i++) {
    string *s = new string();
    gen_string(*s,k,true);
    print_string(*s);
    strs.push_back(*s);
  }
  cout << "Anagrams: " << endl;
  vector<string> r = anagrams(strs);
  for(int i = 0; i < r.size(); i++)
    cout << r[i] << endl;
}
