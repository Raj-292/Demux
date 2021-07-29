// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i;
        
        for(i = 0; i < n; i++) {
            // Check if visited
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            
            // Mark it visited
            nums[abs(nums[i])] = -1*nums[abs(nums[i])];
        }
        
        // NF
        return -1;
    }
};