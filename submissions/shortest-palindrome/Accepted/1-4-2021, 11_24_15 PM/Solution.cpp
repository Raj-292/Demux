// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    string shortestPalindrome(string s) {
        string srev = s;
        int i = 0, j = srev.size()-1;
        
        while(i < j) {
            swap(srev[i], srev[j]);
            i++; j--;
        }
        
        string t = s + "#" + srev;
        int n = t.size();
        // Find out the lps
        vector<int> lps(n, 0);
        
        lps[0] = 0;
        for(i = 1; i < n; i++) {
            
            j = lps[i-1];
            while(j > 0 && t[j] != t[i])
                j = lps[j-1];
            
            if(t[j] != t[i])
                lps[i] = 0;
            else
                lps[i] = j+1;
        }
        
        string append = srev.substr(0, s.size()-lps[n-1]);
        
        return append+s;
    }
};