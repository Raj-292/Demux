// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int hi=n-1,lo=0,mid;
        while(lo<hi){
            mid=lo + (hi-lo)/2;
            if(nums[mid]<nums[0]){
                hi = mid;
            }else{
                lo=mid+1;
            }
        }
        if(nums[lo]<nums[0]){
            return nums[lo];
        }else{
            return nums[0];
        }
        
    }
};