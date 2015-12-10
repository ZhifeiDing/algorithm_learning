#include "leetcode.hpp"

/*
 * Say you have an array for which the ith element is the price of 
 * a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete 
 * at most two transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again).Say you have 
 * an array for which the ith element is the price of a given stock on 
 * day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at 
 * most two transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, 
 * you must sell the stock before you buy again).
 */

int maxProfitIII(vector<int> &prices) {
  int buyFirst = INT_MIN;   // profit of buying the first stock
  int sellFirst = 0;        // profit of selling first stock
  int buySecond = INT_MIN;  // profit of buying second stock
  int sellSecond = 0;       // profit of selling second stock
  for(auto i : prices) {
    tie(buyFirst, sellFirst, buySecond, sellSecond) = make_tuple(max(buyFirst, 0 - i), max(sellFirst, buyFirst + i), max(buySecond, sellFirst - i), max(sellSecond, buySecond + i));
  }
  return sellSecond;
}
