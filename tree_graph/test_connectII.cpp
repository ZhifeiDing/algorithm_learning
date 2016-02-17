#include "leetcode.hpp"

void print_treeII(TreeLinkNode *root) {
  vector<vector<int> > r;

  if( root == NULL )
    return;
  queue<TreeLinkNode*> q;
  q.push(root);

  while( !q.empty() ) {
    int len = q.size();
    vector<int> level;
    for(int i = 0; i < len; ++i) {
      root = q.front();
      q.pop();
      level.push_back(root->val);
      if( root->left != NULL ) q.push(root->left);
      if( root->right!= NULL ) q.push(root->right);
    }
    r.push_back(level);
  }
  for(int i = 0; i < r.size(); ++i) {
    for(auto j : r[i])
      cout << j << "\t";
    cout << endl;
  }
}

void test_connectII() {
    TreeLinkNode ll3(3);
    //TreeLinkNode lr3(4);
    //TreeLinkNode rl3(5);
    TreeLinkNode rr3(6);

    TreeLinkNode l2(1, &ll3, NULL, NULL);
    TreeLinkNode r2(2, NULL, &rr3, NULL);

    TreeLinkNode root(0, &l2, &r2, NULL);
    print_treeII(&root);
    connectII(&root);


    TreeLinkNode *p = &root;
    cout << "connect next = " << endl;
    while( p ) {
        cout << p->val << " ";
        while( p->next ) {
            p = p->next;
            cout << p->val << " ";
        }
        cout << endl;
        p = p->left;
    }
}
