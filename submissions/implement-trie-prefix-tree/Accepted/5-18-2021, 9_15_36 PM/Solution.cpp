// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    /** Initialize your data structure here. */
    
    // structure of a trie
    struct trieNode{
        trieNode* next[26] = {NULL};
        bool isEndHere = false;// optional and keeps on changing
    };
    trieNode* root;
    
    Trie() {
        // root node
        root = new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode* temp = root;
        // traverse char by char
        for(char c: word){
             // create a new node with that character
            if(temp->next[c-'a']==NULL) temp->next[c-'a']=new trieNode();
            // if node exist -> skip
            temp = temp->next[c-'a'];
        }
        // to mark that a string end at this node
        temp->isEndHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode* temp = root;
        for(char c:word){
            if(temp->next[c-'a']==NULL) return false;
            temp=temp->next[c-'a'];
        }
        // we need to check the exact word
        return temp->isEndHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode* temp = root;
        for(char c:prefix){
            if(temp->next[c-'a']==NULL) return false;
            temp=temp->next[c-'a'];
        }
        // only need to check the prefix
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */