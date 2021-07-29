// https://leetcode.com/problems/single-number-ii

class Solution {
public:
   int singleNumber(vector<int>& nums) {
       int c = 0, i, j, count, ci;
        
        // Fix a position
        for(i = 0; i < 32; i++) {
            // Get the count of 1s in this position
            count = 0;
            for(j = 0; j < nums.size(); j++) {
                // Test whether ith bit of nums[j] is set
                // Increment count accordingly
                count += nums[j]&(1<<i) ? 1: 0;
            }
            
            ci = count%3;
            
            // Set the ith bit if needed
            // c = c | (ci<<i);
            if(ci)
                c = c | (1<<i);
        }
        
        return c;
    }
};