#include "leetcode.hpp"

void gen_array(int n, vector<int> & data, int base) {
  //srand((unsigned int)time(NULL));
  for(int i = 0; i < n; i++)
    data.push_back( rand() % base );
}

void print_array(vector<int> & data, const string & s) {
  cout << s << " : ";
  for(int i = 0; i < data.size(); i++)
    cout << data[i] << " ";
  cout << endl;
}

void gen_string(string & s, int n , bool strict ) {

  srand((unsigned int)time(NULL));
  int i = 0;
  unsigned char start = strict ? 'a' : '!';
  unsigned char end = strict ? 'z' : '~';
  const unsigned int base = strict ? 26 : 177;
  while(i < n) {

    unsigned char c = rand() % base + 'a';
    if( c >=  start && c <= end ) {
      s.push_back(c);
      i++;
    }
  }
}

void print_string(string & s) {
  for(int i = 0; i < s.size(); i++)
    cout << s[i];
  cout << endl;
}

void print_list(ListNode* p, const string & s) {
  cout << s << " : ";
  while( p ) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

void gen_list(int n, ListNode* p,bool sorted) {
  // generate two list
  vector<int> a;
  gen_array(n,a,10);
  if(sorted) sort(a.begin(),a.end());

  for(int i = 0; i < n;i++) {
     p->next = new ListNode(a[i],NULL);
     p = p->next;
  }
}

void delete_list(ListNode* p) {
  while( p ) {
    ListNode* n = p;
    p = p->next;
    delete n;
  }
}


/*
 *void print_tree(TreeNode *root, const string &s) {
 *  cout << s << endl;
 *  vector<vector<int> > r = levelOrder(root);
 *  for(int i = 0; i < r.size(); ++i) {
 *    for(auto j : r[i])
 *      cout << j << "\t";
 *    cout << endl;
 *  }
 *}
 */
