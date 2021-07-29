// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Slow & fast
        int slow = 0, fast = 0;
        
        // Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        }while(slow != fast);
        
        // Find the tip of the cycle
        int p2 = slow, p1 = 0;
        
        while(p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        
        return p1;
        
    }
};