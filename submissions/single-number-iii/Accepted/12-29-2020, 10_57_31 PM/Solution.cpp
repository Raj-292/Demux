// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Compute b^f
        long long int bxorf = 0;
        
        for(int i = 0; i < nums.size(); i++)
            bxorf ^= nums[i];
        
        // Compute the mask
        long long int mask = (bxorf)&(~(bxorf-1));
        
        // Divide it into two groups
        long long int xorg1 = 0, xorg2 = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            // Test whether nums[i] has 1 at the position
            // specified by the mask
            // Group 1
            if((nums[i]&mask) == 0)
                xorg1 ^= nums[i];
            // Group 2
            else
                xorg2 ^= nums[i];
        }
        
        return {(int)xorg1, (int)xorg2};
    }
};