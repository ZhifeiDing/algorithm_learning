#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_restoreIpAddresses);
	func_names.push_back("test_restoreIpAddresses");
	test_cases.push_back(test_numIslands);
	func_names.push_back("test_numIslands");
	test_cases.push_back(test_findWords);
	func_names.push_back("test_findWords");
	test_cases.push_back(test_combinationSum3);
	func_names.push_back("test_combinationSum3");
	test_cases.push_back(test_combinationSum);
	func_names.push_back("test_combinationSum");
	test_cases.push_back(test_WordDictionary);
	func_names.push_back("test_WordDictionary");
	test_cases.push_back(test_subsetsWithDup);
	func_names.push_back("test_subsetsWithDup");
	test_cases.push_back(test_threeSumClosest);
	func_names.push_back("test_threeSumClosest");
	test_cases.push_back(test_threeSum);
	func_names.push_back("test_threeSum");
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
