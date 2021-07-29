// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos,i;
        int n=nums.size();
        for(i=n-2;i>=0  && nums[i]>=nums[i+1]; i--);
        pos=i;
        
        if(pos>0)  {
            for(i=n-1;i>pos  && nums[i]<=nums[pos];i--); 
                swap(nums[i],nums[pos]);
            
        }
        i=pos+1;
        int j=n-1;
        while(i<=j) {
           swap(nums[i],nums[j]); 
            i++;
            j--;
        }
        
    }
};