// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n-1, mid;
        
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            
            if((mid-1 < 0 || nums[mid] > nums[mid-1]) && (mid+1 >= n || nums[mid] < nums[mid+1]))
                return nums[mid];
            
            if(mid-1 < 0 || nums[mid] > nums[mid-1]){
                if(mid&1)
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            else{
                if(mid&1)
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        
        return -1;
    }
};