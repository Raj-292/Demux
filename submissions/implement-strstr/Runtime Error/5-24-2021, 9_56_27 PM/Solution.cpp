// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    
    vector<int> generate(string s){
        int n = s.size();
        vector<int> lps(n,0);
        lps[0]=0;
        // make use of 2 pointers
        // i-> running pointer
        // len -> pointing towards prefix -> tell us how much prefix has been matched
        int i=1,len=0;
        while(i<n){
            // abababca -> i=5,len=3
            // i=5 -> aba -> len=3
            // i=6 -> abab -> len = 4
            if(s[len]==s[i]){
                len++;
                lps[i]=len;
                i++;
            } else{
                if(len==0){  
                    // nothing is matching
                    // there isn't amy lps end ends with s[i]
                    lps[i]=len;
                    i++;
                } else{
                    // ababe.....ababc
                    // -> i is at c
                    // make use of already matched abab
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }
    
    int strStr(string text, string pattern) {
        // sizeof pattern
        int m = pattern.size();
        // size of text
        int n = text.size();
        // lps calculation
        vector<int> lps = generate(pattern);
        // i -> text
        // j -> pattern
        for(int i=0,j=0;i<n;){
            if(text[i]==pattern[j]){
                i++;
                j++;
                if(j==m) return (i-j);
            }
            // if there is a mismatch
            else{
                if(j==0) i++;
                else j = lps[j-1];
            }
        }
        return -1;
        
    }
};