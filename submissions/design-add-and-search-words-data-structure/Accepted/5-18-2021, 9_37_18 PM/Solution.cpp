// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trieNode{
        trieNode* next[26] = {NULL};
        bool isEndHere = false;
    };
    trieNode* root;
    
    WordDictionary() {
       root = new trieNode();
    }
    
    void addWord(string word) {
        trieNode* temp = root;
        for(char c: word){
            if(temp->next[c-'a']==NULL) temp->next[c-'a']=new trieNode();
            temp=temp->next[c-'a'];
        }
        temp->isEndHere = true;
    }
    
    bool wildCardSearch(string suffix, trieNode* curr){
        for(int i=0;i<suffix.size();i++){
            char c = suffix[i];
            if(c!='.'){
                if(curr->next[c-'a']==NULL) return false;
                curr=curr->next[c-'a'];
            } else{
                bool found = false;
                int j;
                for(j=0;j<26;j++){
                    if(curr->next[j]!=NULL) found = wildCardSearch(suffix.substr(i+1),curr->next[j]);
                    if(found) return true;
                }
                if(j==26) return false;
            }
        }
        return curr->isEndHere;
    }
    
    bool search(string word) {
        return wildCardSearch(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */