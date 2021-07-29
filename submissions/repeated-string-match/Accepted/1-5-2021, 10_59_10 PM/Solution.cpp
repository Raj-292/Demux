// https://leetcode.com/problems/repeated-string-match

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // Pattern is b
        // Text is a
        // Construct the lps for b
        int nA = a.size(), nB = b.size(), i, j;
        
        vector<int> lps(nB, 0);
        
        lps[0] = 0;
        for(i = 1; i < nB; i++) {
            // Compute lps[i]
            // Initialize to the biggest bubble probable
            j = lps[i-1];
            
            while(j > 0 && b[j] != b[i])
                j = lps[j-1];
            
            if(b[j] != b[i])
                lps[i] = 0;
            else
                lps[i] = j+1;
        }
        
        // Actual KMP
        int total_len = nA*((nB/nA) + 2);
        
        i = 0, j = 0;
        
        while(i < total_len) {
            // Find the first mismatch
            while(j < nB && b[j] == a[i%nA]) {
                i++; j++;
            }
            
            // No mismatch
            if(j == nB)
                return ceil((float)i/nA);
            
            // Mismatch
            if(j == 0)
                i++;
            else
                j = lps[j-1];
            
        }
        
        return -1;
        
    }
};