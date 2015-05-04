#ifndef _TWOSUMDATASTRUCTURE_HPP_
#define _TWOSUMDATASTRUCTURE_HPP_
/*
 * Question:  Design and implement a TwoSum class. It should support the 
 * following operations: add and find.  
 * add(input) – Add the number input to an internal data structure.  
 * find(value) – Find if there exists any pair of numbers which sum is equal 
 * to the value. For example,  add(1); add(3); add(5); find(4) -> true; find(7) -> false 
 */
/*
 * Solution:  add – O(n) runtime, find – O(1) runtime, O(n2) space – Store 
 * pair sums in hash table: We could store all possible pair sums into a hash table. 
 * The extra space needed is in the order of O(n2). You would also need an extra O(n) 
 * space to store the list of added  numbers. Each add operation essentially go through 
 * the list and form new pair sums that go into the hash table. The find operation 
 * involves a single hash table lookup in O(1) runtime.  This method is useful if the 
 * number of find operations far exceeds the number of add operations. 
 */
#include<vector>
#include<unordered_map>
#include<algorithm>


class twoSumADT_hash {
  public:
    void add(const int x);
    bool find(const int x);
    void print();
    explicit twoSumADT_hash() {};
    explicit twoSumADT_hash(int x);
  private:
    std::vector<int> data;
    std::unordered_map<int,std::pair<int,int>> twoSum;
};

class twoSumADT {
  public:
    void add(const int x);
    bool find(const int x);
    void print();
    explicit twoSumADT() {};
    explicit twoSumADT(int x);
  private:
    std::unordered_map<int,int> data;
};
#endif
