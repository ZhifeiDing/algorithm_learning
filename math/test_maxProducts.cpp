#include "leetcode.hpp"

void test_maxProducts() {
  srand((unsigned int)time(NULL));
  vector<string> words;
  int n = rand() % 6;
  cout << "words = \n";
  for(int i = 0; i < n; ++i) {
    string s;
    int m = rand()%20+1;
    gen_string(s, m, true);
    words.push_back(s);
    cout << s << "\n";
  }
  cout << "max product = " << maxProducts(words) << endl;
}
