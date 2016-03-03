#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_longestIncreasingPath);
	func_names.push_back("test_longestIncreasingPath");
	test_cases.push_back(test_connectII);
	func_names.push_back("test_connectII");
	test_cases.push_back(test_connect);
	func_names.push_back("test_connect");
	test_cases.push_back(test_findItinerary);
	func_names.push_back("test_findItinerary");
	test_cases.push_back(test_isValidSerialization);
	func_names.push_back("test_isValidSerialization");
	test_cases.push_back(test_isSymmetric);
	func_names.push_back("test_isSymmetric");
	test_cases.push_back(test_isValidBST);
	func_names.push_back("test_isValidBST");
	test_cases.push_back(test_sortedArrayToBST);
	func_names.push_back("test_sortedArrayToBST");
	test_cases.push_back(test_countSmaller);
	func_names.push_back("test_countSmaller");
	test_cases.push_back(test_binaryTreePaths);
	func_names.push_back("test_binaryTreePaths");
	test_cases.push_back(test_levelOrderBottom);
	func_names.push_back("test_levelOrderBottom");
	test_cases.push_back(test_zigzagLevelOrder);
	func_names.push_back("test_zigzagLevelOrder");
	test_cases.push_back(test_invertTree);
	func_names.push_back("test_invertTree");
	test_cases.push_back(test_findMinHeightTrees);
	func_names.push_back("test_findMinHeightTrees");
	test_cases.push_back(test_lowestCommonAncestorBT);
	func_names.push_back("test_lowestCommonAncestorBT");
	test_cases.push_back(test_flatten);
	func_names.push_back("test_flatten");
	test_cases.push_back(test_postorderTraversal);
	func_names.push_back("test_postorderTraversal");
	test_cases.push_back(test_upsideDownBinaryTree);
	func_names.push_back("test_upsideDownBinaryTree");
	test_cases.push_back(test_pathSum);
	func_names.push_back("test_pathSum");
	test_cases.push_back(test_maxPathSum);
	func_names.push_back("test_maxPathSum");
	test_cases.push_back(test_minDepth);
	func_names.push_back("test_minDepth");
	test_cases.push_back(test_countNodes);
	func_names.push_back("test_countNodes");
	test_cases.push_back(test_validTree);
	func_names.push_back("test_validTree");
	test_cases.push_back(test_closestValue);
	func_names.push_back("test_closestValue");
	test_cases.push_back(test_recoverTree);
	func_names.push_back("test_recoverTree");
	test_cases.push_back(test_levelOrder);
	func_names.push_back("test_levelOrder");
	test_cases.push_back(test_Trie);
	func_names.push_back("test_Trie");
	test_cases.push_back(test_kthSmallest);
	func_names.push_back("test_kthSmallest");
	test_cases.push_back(test_longestConsecutive);
	func_names.push_back("test_longestConsecutive");
	test_cases.push_back(test_verticalOrder);
	func_names.push_back("test_verticalOrder");
	test_cases.push_back(test_buildTreeI);
	func_names.push_back("test_buildTreeI");
	test_cases.push_back(test_hasPathSum);
	func_names.push_back("test_hasPathSum");
	test_cases.push_back(test_preorderTraversal);
	func_names.push_back("test_preorderTraversal");
	test_cases.push_back(test_NumArray);
	func_names.push_back("test_NumArray");
	test_cases.push_back(test_maxDepth);
	func_names.push_back("test_maxDepth");
	test_cases.push_back(test_sumNumbers);
	func_names.push_back("test_sumNumbers");
	test_cases.push_back(test_sortedListToBST);
	func_names.push_back("test_sortedListToBST");
	test_cases.push_back(test_rightSideView);
	func_names.push_back("test_rightSideView");
	test_cases.push_back(test_inorderTraversal);
	func_names.push_back("test_inorderTraversal");
	test_cases.push_back(test_buildTree);
	func_names.push_back("test_buildTree");
	test_cases.push_back(test_lowestCommonAncestor);
	func_names.push_back("test_lowestCommonAncestor");
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
