#include "leetcode.hpp"

void test_grayCode() {
    srand((unsigned int)time(NULL));
    int n = rand()%15;

    cout << n << " bit gray code : " << endl;

    vector<int> r = grayCode(n);
    for(auto i : r)
        cout << i << "\t";
    cout << endl;
}
