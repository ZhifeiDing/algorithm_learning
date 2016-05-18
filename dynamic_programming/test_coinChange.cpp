#include "leetcode.hpp"

void test_coinChange() {
    vector<int> coins = {1, 2, 5};
    srand((unsigned int)time(NULL));
    int amount = rand()%20;
    print_array(coins);
    cout << "amount = " << amount << " , number of change = " << coinChange(coins, amount) << endl;
}
