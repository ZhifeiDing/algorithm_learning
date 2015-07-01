#ifndef __LEETCODE_HPP__
#define __LEETCODE_HPP__

#include<climits>
#include<vector>
#include<list>
#include<iostream>
#include<locale>
#include<ctime>
#include<utility>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<sstream>
#include<string>
#include<stack>
#include "twoSumDataStructure.hpp"

using namespace std;

void gen_array(int n, vector<int> & data, int base_start = 0, int base_end = 97);
void print_array(vector<int> & data, const string s = "Data");
void gen_string(string & s, int n = 13, bool strict = false);
void print_string(string & s);

vector<string> anagrams(vector<string>& strs);
void test_anagrams();

bool isValid(string s);
void test_isValid();

vector<int> twoSum(vector<int> & numbers, int target);
vector<int> twoSum_hash(vector<int> & numbers, int target);
void test_twoSum();

void test_twoSumSort();
vector<int> twoSumSort_binarySearch(vector<int> & numbers, int target);
vector<int> twoSumSort_twoPointer(vector<int> & numbers, int target);
int binarySearch(vector<int> & numbers, int key, int start);

void test_twoSumDataStructure(void);
void test_twoSumDataStructure_hash(void);


bool isPalindrome(string s);
void test_isPalindrome(void);

int strStr(string haystack, string needle);
void test_strStr(void);

string reverseWords(const string & s);
void test_reverseWords(void);


void test_reverseWordsII(void);
void reverseWordsII(char s[],int n);

int atoi(string s);
void test_atoi(void);

bool isNumber(string s);
void test_isNumber(void);


int lengthOfLongestSubstring(string s);
int lengthOfLongestSubstring_map(string s);
void test_lengthOfLongestSubstring(void);


int lengthOfLongestSubstringTwoDistinct(string s);
int lengthOfLongestSubstringTwoDistinct_hash(string s);
void test_lengthOfLongestSubstringTwoDistinct(void);

list<string> findMissingRanges(vector<int> vars, int start, int end);
string getRanges(int from, int start);
void test_findMissingRanges(void);

void test_longestPalindrome(void);
string longestPalindrome(string & s);

void test_isOneEditDistance(void);
bool isOneEditDistance(string & s, string & t);

int sameNum(int X, int A[], int N);
void test_sameNum(void);

int removeElement(vector<int>& nums, int val);
void test_removeElement(void);

vector<vector<string> > solveNQueens(int n);
void nQueens(vector<vector<string> > & r, vector<string> & s, int row);
bool isValid( vector<string> & s, int row, int col);
void test_solveNQueens(void);

int maximumGap(vector<int>& nums);
void test_maximumGap(void);

string reverseWords_2pass(const string & r);

vector<string> findRepeatedDnaSequences(string s);
void test_findRepeatedDnaSequences();

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
void test_merge(void);

vector<string> summaryRanges(vector<int>& nums);
void test_summaryRanges();

#endif

