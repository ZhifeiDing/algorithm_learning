#include "leetcode.hpp"

void test_removeInvalidParentheses() {
  string s = "(a)())()";
  vector<string> r = removeInvalidParentheses(s);
  cout << s << endl << "The valid parentheses : " << endl;
  for(auto i : r )
    cout << i << endl;
  cout << endl;

  s = "()())()";
  r = removeInvalidParentheses(s);
  cout << s << endl << "The valid parentheses : " << endl;
  for(auto i : r )
    cout << i << endl;
  cout << endl;


  s = ")(";
  r = removeInvalidParentheses(s);
  cout << s << endl << "The valid parentheses : " << endl;
  for(auto i : r )
    cout << i << endl;
  cout << endl;
}
