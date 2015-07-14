#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_lowestCommonAncestorBT);
	func_names.push_back("test_lowestCommonAncestorBT");
	test_cases.push_back(test_sumNumbers);
	func_names.push_back("test_sumNumbers");
	test_cases.push_back(test_invertTree);
	func_names.push_back("test_invertTree");
	test_cases.push_back(test_hasPathSum);
	func_names.push_back("test_hasPathSum");
	test_cases.push_back(test_lowestCommonAncestor);
	func_names.push_back("test_lowestCommonAncestor");
	test_cases.push_back(test_countNodes);
	func_names.push_back("test_countNodes");
	test_cases.push_back(test_kthSmallest);
	func_names.push_back("test_kthSmallest");
	test_cases.push_back(test_levelOrderBottom);
	func_names.push_back("test_levelOrderBottom");
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
