#include "leetcode.hpp"

void rotateI(vector<int>& nums, int k) {

     k = k % nums.size();

     if( k == 0 )
          return;

     vector<int> t(nums.size());
     for(int i = nums.size() - k; i < nums.size(); i++)
          t[i + k - nums.size()] = nums[i];
     for(int i = 0; i < nums.size() - k; i++)
          t[i+k] = nums[i];
     copy(t.begin(),t.end(),nums.begin());
}
