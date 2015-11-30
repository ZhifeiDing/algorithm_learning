#include "leetcode.hpp"

/*
 * Say you have an array for which the ith element is the price 
 * of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete 
 * as many transactions as you like (ie, buy one and sell one share 
 * of the stock multiple times) with the following restrictions:
 * 
 * You may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. 
 * (ie, cooldown 1 day)
 * Example:
 * 
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 */

int maxProfitII(vector<int> & prices) {
  if( prices.size() < 2 )
    return 0;

  bool sold = false;
  int lastIdx = -1;
  vector<int> maxProfit(prices.size(), 0);
  for(int i = 1; i < prices.size(); ++i) {
    int val = prices[i] - prices[i-1];
    if( sold ) {
      val = maxProfit[i-1] + val;
    } else {
      val += i > 2 ? maxProfit[i-3] : 0;
      if( lastIdx > 0 )
        val = max(val, maxProfit[i-lastIdx] + prices[i] - prices[i-lastIdx]);
    }
    if( val > maxProfit[i-1] ) {
      sold = true;
      lastIdx = i;
      maxProfit[i] = val;
    } else {
      maxProfit[i] = maxProfit[i-1];
      sold = false;
    }
  }
  return maxProfit[prices.size()-1];
}
