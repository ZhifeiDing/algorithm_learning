#include "leetcode.hpp"
#include "WordDictionary.cpp"

void test_WordDictionary() {
  WordDictionary wordDictionary;
  cout << "Add word : bad dad mad a" << endl;
  wordDictionary.addWord("bad");
  wordDictionary.addWord("dad");
  wordDictionary.addWord("mad");
  wordDictionary.addWord("a");
  string t = wordDictionary.search("pad") ? "find" : "not find";
  cout << "Search word pad : " << t << endl;
  t = wordDictionary.search("bad") ? "find" : "not find";
  cout << "Search word bad : " << t << endl;
  t = wordDictionary.search(".ad") ? "find" : "not find";
  cout << "Search word .ad : " << t << endl;
  t = wordDictionary.search("b..") ? "find" : "not find";
  cout << "Search word b.. : " << t << endl;
  t = wordDictionary.search(".") ? "find" : "not find";
  cout << "Search word . : " << t << endl;
  cout << "Add word : a a" << endl;
  wordDictionary.addWord("a");
  wordDictionary.addWord("a");
  t = wordDictionary.search(".") ? "find" : "not find";
  cout << "Search word . : " << t << endl;
  t = wordDictionary.search("a") ? "find" : "not find";
  cout << "Search word a : " << t << endl;
  t = wordDictionary.search("aa") ? "find" : "not find";
  cout << "Search word aa : " << t << endl;
  t = wordDictionary.search("a") ? "find" : "not find";
  cout << "Search word a : " << t << endl;
  t = wordDictionary.search(".a") ? "find" : "not find";
  cout << "Search word .a : " << t << endl;
  t = wordDictionary.search("a.") ? "find" : "not find";
  cout << "Search word a. : " << t << endl;
}
