// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the position to swap
        // Coming from right, first strictly decreasing number
        int n = nums.size(), i, pos, j;
        
        for(i = n-2; i >= 0 && nums[i] >= nums[i+1]; i--);
        
        pos = i;
        if(pos >= 0) {
            // Find the smallest number greater than this
            // Find the first greater number from the right
            for(i = n-1; i > pos && nums[i] <= nums[pos]; i--);
            
            // i will store the swap position
            swap(nums[pos], nums[i]);
        }
        
        // Reverse nums[pos+1, n-1]
        i = pos+1, j = n-1;
        while(i <= j) {
            swap(nums[i], nums[j]);
            i++; j--;
        }
    }
};