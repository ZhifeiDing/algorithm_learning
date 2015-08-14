#include "leetcode.hpp"
#include "Trie.cpp"

void test_Trie() {
  Trie trie;
  srand((unsigned int)time(NULL));
  int n = rand()%13;
  cout << "Start Insert : " << endl;
  for(int i = 0; i < n; i++) {
    int k = rand()%9;
    string s;
    gen_string(s,k);
    cout << s << endl;
    trie.insert(s);
  }
  cout << endl;
  for(int i = 0; i < n; i++) {
    int k = rand()%9;
    string s;
    gen_string(s,k);
    cout << "Find s : " << s << endl;
    string t = trie.search(s) ? " is a word, " : " is not a word, ";
    t += trie.startsWith(s) ? " is a prefix" : " is not a prefix";
    cout << t << endl;
  }
}
