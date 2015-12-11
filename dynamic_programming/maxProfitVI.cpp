#include "leetcode.hpp"

/*
 * Say you have an array for which the ith element is the price of 
 * a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete 
 * at most k transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again).
 */

int maxProfitHelper(vector<int> &prices) {
  int profit = 0;
  for(int i = 1; i < prices.size(); ++i)
      profit += prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0;
  return profit;
}

int maxProfitVI(int k, vector<int> &prices) {
  if( k >= prices.size()/2 )
    return maxProfitHelper(prices);

  vector<pair<int,int> > buySell(k+1,make_pair(INT_MIN,0));

  for(auto i : prices) {
    for(int j = 1; j <= k; ++j)
      // for every transaction we keep current profit or from previous transaction
      buySell[j] = make_pair(max(buySell[j-1].first - i, buySell[j].first),
                             max(buySell[j-1].second + i, buySell[j].second));
  }

  return buySell[k-1].second;
}
