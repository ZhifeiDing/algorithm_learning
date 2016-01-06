#include "leetcode.hpp"

/*
 * Given n, how many structurally unique BST's (binary search trees) 
 * that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

int numTrees(int n) {
  vector<int> num(n+1, 0);
  num[0] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = i-1; j >= 0; --j) {
      num[i] += num[j] * num[i-j-1];
    }
  }
  return num[n];
}
