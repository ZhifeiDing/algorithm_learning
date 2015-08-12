#include "leetcode.hpp"

/*
 * Given a 2D board and a list of words from the dictionary, find all 
 * words in the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent 
 * cell, where "adjacent" cells are those horizontally or vertically 
 * neighboring. The same letter cell may not be used more than once in a 
 * word.
 * 
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board =
 * 
 * [
 *   ['o','a','a','n'],
 *   ['e','t','a','e'],
 *   ['i','h','k','r'],
 *   ['i','f','l','v']
 * ]
 * Return ["eat","oath"].
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

class TrieNode {
public:
    // Initialize your data structure here.
        vector<TrieNode*> child;
        bool isWord;
        TrieNode() {
          isWord = false;
          child.resize(26);
        };
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    Trie(vector<string> words) {
        root = new TrieNode();
        for(auto i : words)
          insert(i);
    }

    TrieNode* getRoot() {
      return root;
    }

    TrieNode* searchChar(char c, TrieNode* node) {
      if( node == NULL || node->child[c-'a'] == NULL )
        return NULL;
      return node->child[c-'a'];
    }

    // Inserts a word into the trie.
    void insert(string word) {
      TrieNode* node = root;
      for(auto i : word) {
          if( node->child[i - 'a'] == NULL )
            node->child[i - 'a'] = new TrieNode();
          node = node->child[i - 'a'];
      }
      node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = find(word);
        return node != NULL && node->isWord;    
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix); 
    }

private:
    TrieNode* root;

    TrieNode* find(string word) {
      TrieNode* node = root;
      for(auto i : word) {
        if( node->child[i - 'a'] == NULL )
          return NULL;
        node = node->child[i - 'a'];
      }
      return node;
    }
};

void findWordsHelper(vector<vector<char>>& board, int i, int j, Trie* trie, TrieNode* node, vector<string> & r,string & s) {
  if( 0 <= i && i < board.size() && 0 <= j && j < board[0].size() ) {
    node = trie->searchChar(board[i][j],node);
    if( node == NULL )
      return;
    char c = board[i][j];
    // change the board[i][j] to a value thta doesn't exist in words to avoid reuse
    board[i][j] = '#';
    s.push_back(c);
    if( node->isWord ) {
      r.push_back(s);
      node->isWord = false;
    }
    findWordsHelper(board,i,j+1,trie,node,r,s);
    findWordsHelper(board,i,j-1,trie,node,r,s);
    findWordsHelper(board,i+1,j,trie,node,r,s);
    findWordsHelper(board,i-1,j,trie,node,r,s);
    board[i][j] = c;
    s.pop_back();
  }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  vector<string> r;
  Trie* trie = new Trie(words);
  for(int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board[0].size(); j++) {
        string s;
        findWordsHelper(board,i,j,trie, trie->getRoot(), r,s);
    }
    if( r.size() == words.size() )
      break;
  }
  return r;
}
