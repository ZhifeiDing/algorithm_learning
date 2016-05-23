#include "leetcode.hpp"

void test_numDecodings() {
    srand((unsigned int)time(NULL));
    int n = rand();
    string s = to_string(n);
    cout << "s = " << s << endl;
    int r = numDecodings(s);
    cout << "number of ways decoding = " << r << endl;
}
