#include "leetcode.hpp"
#include "ValidWordAbbr.cpp"

void test_ValidWordAbbr() {

  srand((unsigned int)time(NULL));
  int m = rand()%10;
  vector<string> dictionary(m);
  for(int i = 0; i < m; ++i)
    gen_string(dictionary[i], rand()%7+2, true);

  cout << "dictionary = \"" << endl;
  for(int i = 0; i < m; ++i)
    cout << dictionary[i] << endl;
  cout << "\"" << endl;
  
  ValidWordAbbr *vwa = new ValidWordAbbr(dictionary);  
  string s;
  int n = rand()%7 + 2;
  gen_string(s,n,true);
  cout << s << " is " << ( vwa->isUnique(s) ? "" : "not" ) << " unique " << endl;  
  s.resize(0);
  n = rand()%5 + 2;
  gen_string(s,n,true);
  cout << s << " is " << ( vwa->isUnique(s) ? "" : "not" ) << " unique " << endl;  
}
