#include "leetcode.hpp"

/*
 * There are two sorted arrays nums1 and nums2 of size m and n 
 * respectively. Find the median of the two sorted arrays. The 
 * overall run time complexity should be O(log (m+n)).
 */
double findKthElement(vector<int> & nums1, vector<int> & nums2, int k, bool next) {
  int i = 0, j = 0;
  double r = 0;
  for(int cnt = 0; cnt < k; cnt++) {
    if( i < nums1.size() && j < nums2.size() ) {
      if( nums1[i] < nums2[j] )
          r = nums1[i++];
      else
          r = nums2[j++];
    } else if( j < nums2.size() )
      r = nums2[j++];
    else
      r = nums1[i++];
  }
  if( next ) {
    if( i < nums1.size() && j < nums2.size() )
      return ( r + min(nums1[i],nums2[j]))/2;
    if( j < nums2.size() )
      return ( r + nums2[j] ) / 2;
    return ( r + nums1[i] ) / 2;
  }
  return r;
}

double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
  if( nums1.size() == 0 && nums2.size() == 0 )
    return 0;
  int len = nums1.size() + nums2.size();
  return findKthElement(nums1, nums2, ( len + 1 ) / 2, len % 2 == 0);
}

double findMedianSortedArrays_BS(vector<int> & nums1, vector<int> & nums2) {

}
