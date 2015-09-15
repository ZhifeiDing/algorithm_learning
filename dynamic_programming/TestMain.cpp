#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_numSquares);
	func_names.push_back("test_numSquares");
	test_cases.push_back(test_shortestPalindrome);
	func_names.push_back("test_shortestPalindrome");
	test_cases.push_back(test_rob);
	func_names.push_back("test_rob");
	test_cases.push_back(test_robII);
	func_names.push_back("test_robII");
	test_cases.push_back(test_diffWaysToCompute);
	func_names.push_back("test_diffWaysToCompute");
	test_cases.push_back(test_uniquePathsWithObstacles);
	func_names.push_back("test_uniquePathsWithObstacles");
	test_cases.push_back(test_numDistinct);
	func_names.push_back("test_numDistinct");
	test_cases.push_back(test_isInterleave);
	func_names.push_back("test_isInterleave");
	test_cases.push_back(test_maxProfit);
	func_names.push_back("test_maxProfit");
	test_cases.push_back(test_canJump);
	func_names.push_back("test_canJump");
	test_cases.push_back(test_maximalSquare);
	func_names.push_back("test_maximalSquare");
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
