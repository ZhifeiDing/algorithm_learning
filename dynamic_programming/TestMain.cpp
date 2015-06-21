#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_uniquePathsWithObstacles);
	func_names.push_back("test_uniquePathsWithObstacles");
	test_cases.push_back(test_rob);
	func_names.push_back("test_rob");
	test_cases.push_back(test_isInterleave);
	func_names.push_back("test_isInterleave");
	test_cases.push_back(test_canJump);
	func_names.push_back("test_canJump");
	test_cases.push_back(test_numDistinct);
	func_names.push_back("test_numDistinct");
	test_cases.push_back(test_maxProfit);
	func_names.push_back("test_maxProfit");
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
