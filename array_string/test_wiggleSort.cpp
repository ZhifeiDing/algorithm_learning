#include "leetcode.hpp"

void test_wiggleSort() {
    srand((unsigned int)time(NULL));
    int n = rand()%15;
    vector<int> nums;
    gen_array(n, nums);
    print_array(nums);
    wiggleSort(nums);

    print_array(nums);
}
