#include "leetcode.hpp"

/*
 * Say you have an array for which the ith element is the price of a 
 * given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as 
 * many transactions as you like (ie, buy one and sell one share of the 
 * stock multiple times). However, you may not engage in multiple transactions 
 * at the same time (ie, you must sell the stock before you buy again).
 */

int maxProfitII(vector<int> &prices) {
  int buy = INT_MIN;    // profit of buying stock
  int sell = 0;         // profit of selling stock

  for(int i = 0; i < prices.size(); ++i) {
    tie(buy, sell) = make_pair(max(buy, sell - prices[i]), max(sell, buy + prices[i]));
  }
  return sell;
}
