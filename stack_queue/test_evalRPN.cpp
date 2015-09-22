#include "leetcode.hpp"

void test_evalRPN() {
  vector<string> tokens;
  tokens.push_back("2");
  tokens.push_back("1");
  tokens.push_back("+");
  tokens.push_back("3");
  tokens.push_back("*");
  for(int i = 0; i < tokens.size(); i++)
    cout << " \"" << tokens[i] << "\" ";
  cout << endl;
  cout << " = " << evalRPN(tokens) << endl;
  tokens.resize(0);
  tokens.push_back("-1");
  tokens.push_back("1");
  tokens.push_back("*");
  tokens.push_back("-1");
  tokens.push_back("+");
  for(int i = 0; i < tokens.size(); i++)
    cout << " \"" << tokens[i] << "\" ";
  cout << endl;
  cout << " = " << evalRPN(tokens) << endl;
}
