// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), i, res = INT_MIN;
        int prev = 0, curr;
        
        for(i = 1; i <= n; i++) {
            curr = max(prev+nums[i-1], nums[i-1]);
            res = max(res, curr);
            prev = curr;
        }
        
        return res;
    }
};