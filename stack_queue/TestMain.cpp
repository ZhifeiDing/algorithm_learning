#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_topKFrequent);
	func_names.push_back("test_topKFrequent");
	test_cases.push_back(test_increasingTriplet);
	func_names.push_back("test_increasingTriplet");
	test_cases.push_back(test_simplifyPath);
	func_names.push_back("test_simplifyPath");
	test_cases.push_back(test_MinStack);
	func_names.push_back("test_MinStack");
	test_cases.push_back(test_Stack);
	func_names.push_back("test_Stack");
	test_cases.push_back(test_ValidWordAbbr);
	func_names.push_back("test_ValidWordAbbr");
	test_cases.push_back(test_Queue);
	func_names.push_back("test_Queue");
	test_cases.push_back(test_maxSlidingWindow);
	func_names.push_back("test_maxSlidingWindow");
	test_cases.push_back(test_removeDuplicateLetters);
	func_names.push_back("test_removeDuplicateLetters");
	test_cases.push_back(test_evalRPN);
	func_names.push_back("test_evalRPN");
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
