// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        // LPS function
        int n = needle.size(), i, j;
        
        if(n == 0) return 0;
        
        vector<int> lps(n, 0);
        {
            for(int i = 1; i < n; i++) {
                j = lps[i-1];

                while(j > 0 && needle[j] != needle[i]) {
                    j = lps[j-1];
                }

                if(needle[j] == needle[i])
                    lps[i] = j+1;
                else
                    lps[i] = 0;
            }
        }
        
        // Actual KMP
        // I have the lps function
        // lps[i] <-- longest proper prefix which is also a suffix for pattern[0..i]
        i = 0, j = 0;
        
        while(i < haystack.size()) {
            // Find first mismatch
            while(j < n && i < haystack.size() && haystack[i] == needle[j]) {
                i++; j++;
            }
            
            // If pattern found
            if(j == n)
                return (i-n);
            
            // Pattern not found
            // Update j
            if(j == 0)
                i++;
            else
                j = lps[j-1];
        }
        
        return -1;
       
    }
};