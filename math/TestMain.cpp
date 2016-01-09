#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_isPowerOfThree);
	func_names.push_back("test_isPowerOfThree");
	test_cases.push_back(test_missingNumber);
	func_names.push_back("test_missingNumber");
	test_cases.push_back(test_titleToNumber);
	func_names.push_back("test_titleToNumber");
	test_cases.push_back(test_findPeakElement);
	func_names.push_back("test_findPeakElement");
	test_cases.push_back(test_bulbSwitch);
	func_names.push_back("test_bulbSwitch");
	test_cases.push_back(test_maxProducts);
	func_names.push_back("test_maxProducts");
	test_cases.push_back(test_nthSuperUglyNumber);
	func_names.push_back("test_nthSuperUglyNumber");
	test_cases.push_back(test_majorityElement);
	func_names.push_back("test_majorityElement");
	test_cases.push_back(test_countPrimes);
	func_names.push_back("test_countPrimes");
	test_cases.push_back(test_reverseBits);
	func_names.push_back("test_reverseBits");
	test_cases.push_back(test_mySqrt);
	func_names.push_back("test_mySqrt");
	test_cases.push_back(test_myPow);
	func_names.push_back("test_myPow");
	test_cases.push_back(test_numberToWords);
	func_names.push_back("test_numberToWords");
	test_cases.push_back(test_nthUglyNumber);
	func_names.push_back("test_nthUglyNumber");
	test_cases.push_back(test_containsNearbyDuplicate);
	func_names.push_back("test_containsNearbyDuplicate");
	test_cases.push_back(test_rotateI);
	func_names.push_back("test_rotateI");
	test_cases.push_back(test_containsDuplicate);
	func_names.push_back("test_containsDuplicate");
	test_cases.push_back(test_isHappy);
	func_names.push_back("test_isHappy");
	test_cases.push_back(test_divide);
	func_names.push_back("test_divide");
	test_cases.push_back(test_canWinNim);
	func_names.push_back("test_canWinNim");
	test_cases.push_back(test_containsNearbyAlmostDuplicate);
	func_names.push_back("test_containsNearbyAlmostDuplicate");
	test_cases.push_back(test_productExceptSelf);
	func_names.push_back("test_productExceptSelf");
	test_cases.push_back(test_trailingZeroes);
	func_names.push_back("test_trailingZeroes");
	test_cases.push_back(test_isUgly);
	func_names.push_back("test_isUgly");
	test_cases.push_back(test_isPowerOfTwo);
	func_names.push_back("test_isPowerOfTwo");
	test_cases.push_back(test_isPalindrome);
	func_names.push_back("test_isPalindrome");
	test_cases.push_back(test_searchMatrix);
	func_names.push_back("test_searchMatrix");
	test_cases.push_back(test_calculateII);
	func_names.push_back("test_calculateII");
	test_cases.push_back(test_calculate);
	func_names.push_back("test_calculate");
	test_cases.push_back(test_computeArea);
	func_names.push_back("test_computeArea");
	test_cases.push_back(test_rotate);
	func_names.push_back("test_rotate");
	test_cases.push_back(test_singleNumber);
	func_names.push_back("test_singleNumber");
	test_cases.push_back(test_convertToTitle);
	func_names.push_back("test_convertToTitle");
	test_cases.push_back(test_addDigits);
	func_names.push_back("test_addDigits");
	test_cases.push_back(test_countDigitOne);
	func_names.push_back("test_countDigitOne");
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
