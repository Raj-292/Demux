// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), i, cum_sum = 0, res = 0;
        
        unordered_map<int, int> m;
        
        // Empty prefix array
        m[0] = 1;
        
        for(i = 0; i < n; i++) {
            cum_sum += nums[i];
            
            res += m[cum_sum-k];
            
            m[cum_sum]++;
        }
        
        return res;
    }
};