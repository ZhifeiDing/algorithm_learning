#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_integerBreak);
	func_names.push_back("test_integerBreak");
	test_cases.push_back(test_numTrees);
	func_names.push_back("test_numTrees");
	test_cases.push_back(test_longestValidParentheses);
	func_names.push_back("test_longestValidParentheses");
	test_cases.push_back(test_maxProfit);
	func_names.push_back("test_maxProfit");
	test_cases.push_back(test_lengthOfLIS);
	func_names.push_back("test_lengthOfLIS");
	test_cases.push_back(test_isInterleave);
	func_names.push_back("test_isInterleave");
	test_cases.push_back(test_NumMatrix);
	func_names.push_back("test_NumMatrix");
	test_cases.push_back(test_numSquares);
	func_names.push_back("test_numSquares");
	test_cases.push_back(test_diffWaysToCompute);
	func_names.push_back("test_diffWaysToCompute");
	test_cases.push_back(test_robII);
	func_names.push_back("test_robII");
	test_cases.push_back(test_numDistinct);
	func_names.push_back("test_numDistinct");
	test_cases.push_back(test_uniquePathsWithObstacles);
	func_names.push_back("test_uniquePathsWithObstacles");
	test_cases.push_back(test_numDecodings);
	func_names.push_back("test_numDecodings");
	test_cases.push_back(test_maxProfitII);
	func_names.push_back("test_maxProfitII");
	test_cases.push_back(test_maxProfitVI);
	func_names.push_back("test_maxProfitVI");
	test_cases.push_back(test_maxProfitIII);
	func_names.push_back("test_maxProfitIII");
	test_cases.push_back(test_maximalSquare);
	func_names.push_back("test_maximalSquare");
	test_cases.push_back(test_maxProfitCoolDown);
	func_names.push_back("test_maxProfitCoolDown");
	test_cases.push_back(test_shortestPalindrome);
	func_names.push_back("test_shortestPalindrome");
	test_cases.push_back(test_maxCoins);
	func_names.push_back("test_maxCoins");
	test_cases.push_back(test_rob);
	func_names.push_back("test_rob");
	test_cases.push_back(test_canJump);
	func_names.push_back("test_canJump");
	test_cases.push_back(test_NumArray);
	func_names.push_back("test_NumArray");
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
