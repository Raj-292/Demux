// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        long s=0, n = nums.size();
        long t = (n-1)*n/2;
        for(int i=0;i<n;i++){
            s += nums[i];
        }
        return s-t;
    }
};