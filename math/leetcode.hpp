#ifndef __LEETCODE_HPP__
#define __LEETCODE_HPP__

#include<climits>
#include<vector>
#include<list>
#include<iostream>
#include<locale>
#include<ctime>
#include<utility>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<sstream>
#include<string>
#include<cstddef>
#include<cstdlib>

using namespace std;

void gen_array(int n, vector<int> & data, int base = 97);
void print_array(vector<int> & data);
void gen_string(string & s, int n , bool strict );
void print_string(string & s);

void rotateI(vector<int>& nums, int k);
void test_rotateI();


class ListNode {
  public:
    int val;
    ListNode* next;
    explicit ListNode() {};
    explicit ListNode(int x) : val(x) {};
    explicit ListNode(int x,ListNode* l) : val(x),next(l) {};
};

int trailingZeroes(int n);
void test_trailingZeroes(void);

uint32_t reverseBits(uint32_t n);
uint32_t reverseBits_lookup(uint32_t n);
void test_reverseBits();

int findPeakElement(vector<int>& nums);
void test_findPeakElement(void);

void test_isHappy(void);
bool isHappy(int n);

int singleNumber(vector<int>& nums);
void test_singleNumber();

void rotate(vector<vector<int> > & matrix);
void test_rotate();

int calculate(string s);
void test_calculate(void);

int countPrimes(int n);
void test_countPrimes();
int calculateII(string s);
void test_calculateII();

vector<int> majorityElement(vector<int> & nums);
void test_majorityElement();

bool isPowerOfTwo_online(int n);
bool isPowerOfTwo(int n);
void test_isPowerOfTwo();

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
void test_computeArea();

int countDigitOne(int n);
void test_countDigitOne();

vector<int> productExceptSelf(vector<int>& nums);
void test_productExceptSelf();
#endif

