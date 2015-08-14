#include "leetcode.hpp"

/*
 * Implement a trie with insert, search, and startsWith methods.
 * 
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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
