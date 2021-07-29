// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1,p2=0,n=nums.size();
        if(n==0 || n==1) return n;
        for(p1=1;p1<n;p1++)
        {
         if(nums[p1]!=nums[p2])
         {
             p2=p2+1;
            swap(nums[p1],nums[p2]);
         }
        }
        
        return p2+1;
    }
};