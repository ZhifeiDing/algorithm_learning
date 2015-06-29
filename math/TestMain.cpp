#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_calculate);
	func_names.push_back("test_calculate");
	test_cases.push_back(test_rotate);
	func_names.push_back("test_rotate");
	test_cases.push_back(test_singleNumber);
	func_names.push_back("test_singleNumber");
	test_cases.push_back(test_isHappy);
	func_names.push_back("test_isHappy");
	test_cases.push_back(test_reverseBits);
	func_names.push_back("test_reverseBits");
	test_cases.push_back(test_findPeakElement);
	func_names.push_back("test_findPeakElement");
	test_cases.push_back(test_trailingZeroes);
	func_names.push_back("test_trailingZeroes");
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
