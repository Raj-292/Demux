// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        Finding the first position of element in sorted array
        Is BS applicable?
        p(x): F*T*: x >= target FFFFTTT, first T
        */
        int n = nums.size(), lo, hi, mid;
        vector<int> res;
        
        if(n == 0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
            
        lo = 0, hi = n-1;
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            
            if(nums[mid] >= target)
                hi = mid;
            else
                lo = mid+1;
        }
        if(nums[lo] == target)
            res.push_back(lo);
        else
            res.push_back(-1);
        
        /* Finding the last position of element in sorted array
        Is BS applicable?
        p(x): F*T*: x > target, last F
        */
        
        lo = 0, hi = n-1;
        while(lo < hi){
            mid = lo + (hi-lo+1)/2;
                
            if(nums[mid] > target)
                hi = mid-1;
            else
                lo = mid;
        }
        if(nums[lo] == target)
            res.push_back(lo);
        else
            res.push_back(-1);
        
        return res;
        
    }
};