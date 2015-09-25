#include "leetcode.hpp"

void test_simplifyPath() {
  string path = "/a/./b/../../c/";
  string r = simplifyPath(path);
  cout << path << " = " << r << endl;
  path = "/home/";
  r = simplifyPath(path);
  cout << path << " = " << r << endl;
  path = "///./";
  r = simplifyPath(path);
  cout << path << " = " << r << endl;
}
