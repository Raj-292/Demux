// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i, n= citations.size(), ans = INT_MIN;
        for(i=0;i<n;i++){
            ans = max(ans, min(citations[i], n-i));
        }
        return ans;
    }
};