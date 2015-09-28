#include "leetcode.hpp"

void test_restoreIpAddresses() {
  srand((unsigned int)time(NULL));
  string s;
  int n = rand()%20;
  for(int i = 0; i < n; i++)
    s.push_back(rand()%10 +'0');
  cout << "s = " << s << endl;
  vector<string> r = restoreIpAddresses(s);
  cout << "IP : " << endl;
  for(auto itr : r)
    cout << itr << endl;
}
