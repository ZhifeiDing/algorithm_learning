#include "leetcode.hpp"

int main() {
  vector<int> *a = new vector<int>(26,0);
  for(auto i : *a)
    cout << i << " ";
  cout << endl;
  vector<int> b(26);
  for(auto i : b)
    cout << i << " ";
  cout << endl;
  vector<string> c(26,"abc");
  for(auto i : c)
    cout << i << " ";
  cout << endl;
  return 0;
}
