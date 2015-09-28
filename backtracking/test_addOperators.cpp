#include "leetcode.hpp"

void test_addOperators() {
  srand((unsigned int)time(NULL));
  int n = rand()%9;
  string s;
  for(int i = 0; i < n; i++)
    s.push_back(rand()%10+'0');
  int target = rand()%20;

  s = "105";
  target = 5;

  s = to_string(INT_MAX);
  target = INT_MIN;
  cout << "num = " << s << " , target = " << target << endl;
  vector<string> r = addOperators(s, target);
  for(int i = 0; i < r.size(); i++)
    cout << i << " : " << r[i] << endl;

}
