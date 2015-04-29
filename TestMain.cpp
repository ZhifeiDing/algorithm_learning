#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_sameNum);
	func_names.push_back("test_sameNum");
	test_cases.push_back(test_isOneEditDistance);
	func_names.push_back("test_isOneEditDistance");
	test_cases.push_back(test_findMissingRanges);
	func_names.push_back("test_findMissingRanges");
	test_cases.push_back(test_lengthOfLongestSubstring);
	func_names.push_back("test_lengthOfLongestSubstring");
	test_cases.push_back(test_twoSumSort);
	func_names.push_back("test_twoSumSort");
	test_cases.push_back(test_twoSumDataStructure);
	func_names.push_back("test_twoSumDataStructure");
	test_cases.push_back(test_twoSum);
	func_names.push_back("test_twoSum");
	test_cases.push_back(test_reverseWordsII);
	func_names.push_back("test_reverseWordsII");
	test_cases.push_back(test_longestPalindrome);
	func_names.push_back("test_longestPalindrome");
	test_cases.push_back(test_isNumber);
	func_names.push_back("test_isNumber");
	test_cases.push_back(test_strStr);
	func_names.push_back("test_strStr");
	test_cases.push_back(test_isPalindrome);
	func_names.push_back("test_isPalindrome");
	test_cases.push_back(test_lengthOfLongestSubstringTwoDistinct);
	func_names.push_back("test_lengthOfLongestSubstringTwoDistinct");
	test_cases.push_back(test_atoi);
	func_names.push_back("test_atoi");
	test_cases.push_back(test_reverseWords);
	func_names.push_back("test_reverseWords");
	while(true) {
		char select;
		cout << "Please choose a case:" << endl;
		for(int i = 0; i < func_names.size(); i++)
			cout << "[ " << i << "	]: " << func_names[i] << endl;
			cin >> select;
			if( select == 'q' || select == 'Q')
			  break;
			int s = (unsigned int)atoi(&select);
			if( s >= test_cases.size() ) {
			  cout << "Wrong choices !" << endl;
			  continue;
			}
			(*test_cases[s])();
	}
	return 0;
}
