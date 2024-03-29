// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), i, res = INT_MIN;
        vector<int> minProd(n+1, 1);
        vector<int> maxProd(n+1, 1);
        
        for(i = 1; i <= n; i++) {
            minProd[i] = min(nums[i-1], min(nums[i-1]*minProd[i-1], nums[i-1]*maxProd[i-1]));
            maxProd[i] = max(nums[i-1], max(nums[i-1]*minProd[i-1], nums[i-1]*maxProd[i-1]));
            res = max(res, maxProd[i]);
        }
        
        return res;
    }
};