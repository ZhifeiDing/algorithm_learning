#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_multiply);
	func_names.push_back("test_multiply");
	test_cases.push_back(test_reverseVowels);
	func_names.push_back("test_reverseVowels");
	test_cases.push_back(test_wiggleSortII);
	func_names.push_back("test_wiggleSortII");
	test_cases.push_back(test_firstMissingPositive);
	func_names.push_back("test_firstMissingPositive");
	test_cases.push_back(test_firstBadVersion);
	func_names.push_back("test_firstBadVersion");
	test_cases.push_back(test_solveNQueens);
	func_names.push_back("test_solveNQueens");
	test_cases.push_back(test_longestPalindrome);
	func_names.push_back("test_longestPalindrome");
	test_cases.push_back(test_findMissingRanges);
	func_names.push_back("test_findMissingRanges");
	test_cases.push_back(test_isNumber);
	func_names.push_back("test_isNumber");
	test_cases.push_back(test_atoi);
	func_names.push_back("test_atoi");
	test_cases.push_back(test_twoSumSort);
	func_names.push_back("test_twoSumSort");
	test_cases.push_back(test_lengthOfLongestSubstringTwoDistinct);
	func_names.push_back("test_lengthOfLongestSubstringTwoDistinct");
	test_cases.push_back(test_convert);
	func_names.push_back("test_convert");
	test_cases.push_back(test_insert);
	func_names.push_back("test_insert");
	test_cases.push_back(test_moveZeroes);
	func_names.push_back("test_moveZeroes");
	test_cases.push_back(test_reverseString);
	func_names.push_back("test_reverseString");
	test_cases.push_back(test_getHint);
	func_names.push_back("test_getHint");
	test_cases.push_back(test_isValid);
	func_names.push_back("test_isValid");
	test_cases.push_back(test_isOneEditDistance);
	func_names.push_back("test_isOneEditDistance");
	test_cases.push_back(test_findMedianSortedArrays);
	func_names.push_back("test_findMedianSortedArrays");
	test_cases.push_back(test_minSubArrayLen);
	func_names.push_back("test_minSubArrayLen");
	test_cases.push_back(test_anagrams);
	func_names.push_back("test_anagrams");
	test_cases.push_back(test_wiggleSort);
	func_names.push_back("test_wiggleSort");
	test_cases.push_back(test_merge);
	func_names.push_back("test_merge");
	test_cases.push_back(test_wordPattern);
	func_names.push_back("test_wordPattern");
	test_cases.push_back(test_removeElement);
	func_names.push_back("test_removeElement");
	test_cases.push_back(test_largestNumber);
	func_names.push_back("test_largestNumber");
	test_cases.push_back(test_isAnagram);
	func_names.push_back("test_isAnagram");
	test_cases.push_back(test_findRepeatedDnaSequences);
	func_names.push_back("test_findRepeatedDnaSequences");
	test_cases.push_back(test_reverseWordsII);
	func_names.push_back("test_reverseWordsII");
	test_cases.push_back(test_summaryRanges);
	func_names.push_back("test_summaryRanges");
	test_cases.push_back(test_reverseWords);
	func_names.push_back("test_reverseWords");
	test_cases.push_back(test_maximumGap);
	func_names.push_back("test_maximumGap");
	test_cases.push_back(test_isPalindrome);
	func_names.push_back("test_isPalindrome");
	while(true) {
		string select;
		cout << "Please choose a case:" << endl;
		for(int i = 0; i < func_names.size(); i++)
			cout << "[ " << i << "	]: " << func_names[i] << endl;
		getline(cin , select);
		if( select == "q" || select == "Q")
		  break;
		int s = (unsigned int)stoi(select);
		if( s >= test_cases.size() ) {
		  cout << "Wrong choices !" << endl;
		  continue;
		}
		(*test_cases[s])();
	}
	return 0;
}
