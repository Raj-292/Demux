// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0;
        
        while(nums[i] > 0) {
            nums[i] = -1*nums[i];
            i = abs(nums[i]);
        }
        
        return i;
    }
};