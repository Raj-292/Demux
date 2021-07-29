// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0, temp;
        
        while(nums[i] != -1) {
            temp = i;
            i = nums[i];
            nums[temp] = -1;
        }
        
        return i;
    }
};