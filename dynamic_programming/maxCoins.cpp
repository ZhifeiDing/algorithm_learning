#include "leetcode.hpp"

/*
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with 
 * a number on it represented by array nums. You are asked to burst all 
 * the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] 
 * coins. Here left and right are adjacent indices of i. After the burst, 
 * the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note: 
 * (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you 
 * can not burst them.
 * (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * Example:
 * 
 * Given [3, 1, 5, 8]
 * 
 * Return 167
 * 
 *     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 *    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 */

/*
 * we can divide the problem into two sub-issues that divided by the last burst ballons
 */
int maxCoins(vector<int> &nums) {
  vector<int> num(nums.size()+2);
  int n = 1;
  // remove any zero numbwers first
  for(auto itr : nums)
    if( itr )
      num[n++] = itr;

  // add the sentinel 
  num[0] = num[n++] = 1;

  // for every element we take it as the last one to burst 
  // and increase the length step by step
  vector<vector<int> > coins(n, vector<int>(n,0));
  for(int len = 2; len < n; ++len)
    for(int left = 0; left < n - len; ++left) {
      int right = left + len;
      for(int i = left + 1; i < right; ++i) {
        coins[left][right] = max(coins[left][right], num[left] * num[i] * num[right] +
            coins[left][i] + coins[i][right]);
      }
    }

  return coins[0][n-1];
}


/*
 * we can also use divide & conquer with memorization from top to bottom
 */
int maxCoinsHelper(vector<int> &num, int left, int right, vector<vector<int> > &coins) {
  if( left + 1 == right )
    return 0;
  if( coins[left][right] > 0 )
    return coins[left][right];

  for(int i = left + 1; i < right; ++i)
    coins[left][right] = max(coins[left][right], num[left] * num[i] * num[right] + maxCoinsHelper(num, left, i, coins) +
                                                       maxCoinsHelper(num, i, right, coins));
  return coins[left][right];
}

int maxCoins_dc(vector<int> &nums) {
  vector<int> num(nums.size()+2);
  int n = 1;
  // remove any zero numbwers first
  for(auto itr : nums)
    if( itr )
      num[n++] = itr;

  // add the sentinel 
  num[0] = num[n++] = 1;
  vector<vector<int> > coins(n, vector<int>(n,0));
  maxCoinsHelper(num, 0, n - 1, coins);
  return coins[0][n-1];
}
