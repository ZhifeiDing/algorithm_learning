#include "leetcode.hpp"

void test_topKFrequent() {
    srand((unsigned int)time(NULL));
    vector<int> nums;
    int n = rand()%20;
    int k = n ? rand()%n : 0;
    gen_array(n, nums);
    print_array(nums);
    cout << " k = " << k << endl;
    vector<int> r = topKFrequent(nums, k);

    print_array(r);
}
