// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        
        int n = citations.size(), i, j;
        
        if(n == 0) return 0;
        
        if(citations[0] <= 0) return 0;
        
        for(i = 1; i < n; i++){
            if(citations[i-1] >= i && citations[i] <= i)
                return i;
        }
        
        if(citations[n-1] >= n)
            return n;
        
        return n;
    }
};