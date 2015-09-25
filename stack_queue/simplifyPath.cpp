#include "leetcode.hpp"

/*
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 * 
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' 
 * together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

string simplifyPath(string path) {
    stack<string> s;
    string r;
    int i = 1;
    while( i < path.size() ) {
        int j = 0;
        while( i+j < path.size() && path[i+j] != '/' )
            ++j;
        string t = path.substr(i,j);
        if( t == ".." ) {
          if( !s.empty() ) {
              s.pop();
              s.pop();
          }
        } else if( t == ""  || t == "." ){
        } else {
            s.push("/");
            s.push(t);
        }
        i += j+1;
    }
    if( s.empty() && path.size() != 0 )
      return "/";
    while( !s.empty() ) {
        r = s.top() + r;
        s.pop();
    }
    return r;
}
