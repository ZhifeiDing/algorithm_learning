#include "leetcode.hpp"

void test_wiggleSortII() {
    srand((unsigned int)time(NULL));
    int n = rand()%15;
    vector<int> nums;
    gen_array(n, nums);
    print_array(nums);
    wiggleSortII(nums);

    print_array(nums);
}
