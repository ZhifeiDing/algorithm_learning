#include "leetcode.hpp"

void test_isValidSerialization() {
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string s = isValidSerialization(preorder) ? " valid " : "not valid";
    cout << "preorder = " << preorder << " is " << s << endl;

    preorder = "9,#,#,1";
    s = isValidSerialization(preorder) ? " valid " : "not valid";
    cout << "preorder = " << preorder << " is " << s << endl;
}
