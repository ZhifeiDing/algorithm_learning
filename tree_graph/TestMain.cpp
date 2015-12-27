#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_sortedListToBST);
	func_names.push_back("test_sortedListToBST");
	test_cases.push_back(test_verticalOrder);
	func_names.push_back("test_verticalOrder");
	test_cases.push_back(test_sortedArrayToBST);
	func_names.push_back("test_sortedArrayToBST");
	test_cases.push_back(test_buildTreeI);
	func_names.push_back("test_buildTreeI");
	test_cases.push_back(test_maxDepth);
	func_names.push_back("test_maxDepth");
	test_cases.push_back(test_zigzagLevelOrder);
	func_names.push_back("test_zigzagLevelOrder");
	test_cases.push_back(test_lowestCommonAncestor);
	func_names.push_back("test_lowestCommonAncestor");
	test_cases.push_back(test_sumNumbers);
	func_names.push_back("test_sumNumbers");
	test_cases.push_back(test_minDepth);
	func_names.push_back("test_minDepth");
	test_cases.push_back(test_binaryTreePaths);
	func_names.push_back("test_binaryTreePaths");
	test_cases.push_back(test_buildTree);
	func_names.push_back("test_buildTree");
	test_cases.push_back(test_countSmaller);
	func_names.push_back("test_countSmaller");
	test_cases.push_back(test_rightSideView);
	func_names.push_back("test_rightSideView");
	test_cases.push_back(test_hasPathSum);
	func_names.push_back("test_hasPathSum");
	test_cases.push_back(test_Trie);
	func_names.push_back("test_Trie");
	test_cases.push_back(test_countNodes);
	func_names.push_back("test_countNodes");
	test_cases.push_back(test_invertTree);
	func_names.push_back("test_invertTree");
	test_cases.push_back(test_findMinHeightTrees);
	func_names.push_back("test_findMinHeightTrees");
	test_cases.push_back(test_kthSmallest);
	func_names.push_back("test_kthSmallest");
	test_cases.push_back(test_lowestCommonAncestorBT);
	func_names.push_back("test_lowestCommonAncestorBT");
	test_cases.push_back(test_levelOrder);
	func_names.push_back("test_levelOrder");
	test_cases.push_back(test_levelOrderBottom);
	func_names.push_back("test_levelOrderBottom");
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
