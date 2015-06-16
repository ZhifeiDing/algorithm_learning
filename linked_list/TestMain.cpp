#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_mergeKLists);
	func_names.push_back("test_mergeKLists");
	test_cases.push_back(test_deleteDuplicates);
	func_names.push_back("test_deleteDuplicates");
	test_cases.push_back(test_copyRandomList);
	func_names.push_back("test_copyRandomList");
	test_cases.push_back(test_reverseBetween);
	func_names.push_back("test_reverseBetween");
	test_cases.push_back(test_swapPairs);
	func_names.push_back("test_swapPairs");
	test_cases.push_back(test_removeElements);
	func_names.push_back("test_removeElements");
	test_cases.push_back(test_mergeTwoLists);
	func_names.push_back("test_mergeTwoLists");
	test_cases.push_back(test_addTwoNumbers);
	func_names.push_back("test_addTwoNumbers");
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
