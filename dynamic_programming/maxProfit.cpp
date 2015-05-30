#include "leetcode.hpp"

/*
 * Say you have an array for which the ith element is the price of 
 * a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), design an algorithm 
 * to find the maximum profit.
 */
int maxProfit(vector<int>& prices) {
    // f[i] = max(f[i-1] + prices[i] - prices[i-1], f[i-1])
    // f[0] = 0
    int maxSum = 0, sum = 0;
    for(int i = 1; i < prices.size(); i++) {
        sum += prices[i] - prices[i-1];
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);
    }
    return maxSum;
}
