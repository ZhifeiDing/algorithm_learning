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
#include<set>

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

bool containsNearbyDuplicate(vector<int> & nums, int k);
void test_containsNearbyDuplicate();

bool containsDuplicate(vector<int> & nums);
void test_containsDuplicate();

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
void test_containsNearbyAlmostDuplicate();

bool searchMatrix(vector<vector<int>>& matrix, int target);
void test_searchMatrix();

int addDigits(int num);
void test_addDigits();

string convertToTitle(int n);
void test_convertToTitle();

int titleToNumber(string s);
void test_titleToNumber();

bool isUgly(int num);
void test_isUgly();

int nthUglyNumber(int n);
void test_nthUglyNumber();
int nthUglyNumber_set(int n);
int nthUglyNumber_DP(int n);

int missingNumber(vector<int> & nums);
void test_missingNumber();

string numberToWords(int num);
void test_numberToWords();

bool isPalindrome(int x);
void test_isPalindrome();

double myPow(double x, int n);
void test_myPow();

int mySqrt(int x);
void test_mySqrt();

bool canWinNim(int n);
void test_canWinNim();

int divide(int dividend, int divisor);
void test_divide();
int divide_bs(int dividend, int divisor);
#endif

