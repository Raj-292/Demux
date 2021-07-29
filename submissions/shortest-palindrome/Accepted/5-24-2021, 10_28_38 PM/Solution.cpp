// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string res = s+"#"+rev;
        int n = res.length();
        vector<int> lps(n,0);
        int i=1,j=0;
        while(i<n){
            if(res[i]==res[j]){
                j++;
                lps[i++]=j;
            } else{
                if(j!=0) j=lps[j-1];
                else lps[i++]=j;
            }
        }
        // palindrome lenght -> lps[n-1]
        // remaining -> rev.size()-lps[n-1]
        return rev.substr(0,rev.size()-lps[n-1])+s;
    }
};