#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool wordEnd;
    TrieNode(){
        wordEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void Insert(const string& s){
        TrieNode* cur = root;
        for(char c : s){
            int i = c - 'a';
            if(cur->child[i] == NULL){
                cur->child[i] = new TrieNode();
            }
            cur = cur->child[i];
        }
        cur->wordEnd = true;
    }
    bool Search(const string& s){
        TrieNode* cur = root;
        for(char c : s){
            int i = c - 'a';
            if(cur->child[i] == NULL){
                return false;
            }
            cur = cur->child[i];
        }
        return cur->wordEnd;
    }
};

int main(){
    return 0;
}