#include "leetcode.hpp"

void test_increasingTriplet() {
    srand((unsigned int)time(NULL));
    vector<int> nums;
    int n = rand()%20;
    gen_array(n, nums);
    print_array(nums);
    string s = increasingTriplet(nums) ? "has triplet increasing " : "not have triplet increasing";
    cout << s << endl;
}
