#include "leetcode.hpp"
/*
 * Design a data structure that supports the following two operations:
 * 
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string 
 * containing only letters a-z or .. A . means it can represent any one 
 * letter.
 * 
 * For example:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 */

class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> child;
    
    TrieNode() {
        isWord = false;
        child.resize(26);
    }
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for(auto i : word) {
            if( node->child[i-'a'] == NULL )
                node->child[i-'a'] = new TrieNode();
            node = node->child[i-'a'];
        }
        node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return find(word, root, 0);
    }
    
    WordDictionary() {
        root = new TrieNode();
    }
private:
    TrieNode* root;
    
    bool find(string &word, TrieNode *node, int idx) {
        for(int i = idx; i < word.size(); i++) {
            if( word[i] == '.' ) {
                bool r = false;
                i++;
                for(auto itr : node->child) {
                    r |= (node != NULL ) && find(word,itr,i);
                    if( r )
                        return r;
                }
                return r;
            } else {
                if( node == NULL || node->child[word[i]-'a'] == NULL )
                    return NULL;
                node = node->child[word[i]-'a'];
            }
        }
        return node != NULL && node->isWord;
    }
};

