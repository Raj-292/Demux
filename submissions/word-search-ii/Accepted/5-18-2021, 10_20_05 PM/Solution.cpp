// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    vector<string> res;
    int m,n;
    
    struct trieNode{
        trieNode* next[26] = {NULL};
        bool isEndHere = false;
        // store the complete word if end there
        string wordTillHere = "";
    };
    trieNode* root = new trieNode();
    
    void buildTrie(string word){
        trieNode* temp = root;
        for(char c:word){
            if(temp->next[c-'a']==NULL) temp->next[c-'a']=new trieNode();
            temp=temp->next[c-'a'];
        }
        temp->isEndHere = true;
        // store the word ending here
        temp->wordTillHere = word;
    }
    
    void dfs(int i,int j,trieNode* node,vector<vector<char>>& board){
        // cout << i << j << endl;
        char c = board[i][j];
        // if current character does not exists
        if(c=='$' ||node->next[c-'a']==NULL) return;
        // move to next node in trie
        node = node->next[c-'a'];
        // create logic for finding answer
        // check if ANY WORD END HERE
        if(node->isEndHere){
            res.push_back(node->wordTillHere);
            // reset the string to avoid duplicates
            node->wordTillHere = "";
            node->isEndHere = false;
        }
        // recursive calls if current node exists
        board[i][j]='$';
        if(i>0) dfs(i-1,j,node,board);
        if(i<m-1) dfs(i+1,j,node,board);
        if(j>0) dfs(i,j-1,node,board);
        if(j<n-1) dfs(i,j+1,node,board);
        board[i][j]=c;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create the trie with words array
        for(string s:words){
            buildTrie(s);
        }
        m = board.size();
        if(board.size()==0) return res;
        n = board[0].size();
        // traverse through each unit of metric
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,root,board);
            }
        }
        return res;
    }
};