#include "leetcode.hpp"
#include "MedianFinder.cpp"

void test_MedianFinder() {
  MedianFinder mf;
  srand((unsigned int)time(NULL));
  vector<int> v;
  v.push_back(rand()%20);
  mf.addNum(v.back());
  print_array(v);
  cout << "Median = " << mf.findMedian() << endl << endl;
  
  v.push_back(rand()%20);
  mf.addNum(v.back());
  print_array(v);
  cout << "Median = " << mf.findMedian() << endl << endl;
  
  v.push_back(rand()%20);
  mf.addNum(v.back());
  print_array(v);
  cout << "Median = " << mf.findMedian() << endl << endl;
  
  v.push_back(rand()%20);
  mf.addNum(v.back());
  print_array(v);
  cout << "Median = " << mf.findMedian() << endl << endl;
  
  v.push_back(rand()%20);
  mf.addNum(v.back());
  print_array(v);
  cout << "Median = " << mf.findMedian() << endl << endl;
  
  v.push_back(rand()%20);
  mf.addNum(v.back());
  print_array(v);
  cout << "Median = " << mf.findMedian() << endl << endl;
  
}
