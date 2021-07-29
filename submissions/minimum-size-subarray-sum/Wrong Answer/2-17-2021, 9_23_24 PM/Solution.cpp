// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int getLargestLessEquals(vector<int> &ar, int target) {
        int n = ar.size(), lo, mid, hi;
        
        lo = 0, hi = n-1;
        // F*T*
        // p(x): arr(x) > target
        // last F
        while(lo < hi) {
            mid = lo + (hi-lo+1)/2;
            
            if(ar[mid] > target)
                hi = mid-1;
            else
                lo = mid;
        }
        
        // Sanity check
        if(ar[lo] <= target)
            return lo;
        return -1;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix_sum;
        int cum_sum = 0, window_length, res = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            // Ending at i, let's find out the largest prefix sum <= cum_sum-target
            cum_sum += nums[i];
            prefix_sum.push_back(cum_sum);
            
            // Binary Search
            int idx = getLargestLessEquals(prefix_sum, cum_sum-target);
            
            // Everything is greater than cum_sum-target
            if(idx == -1)
                continue;
            else {
                window_length = i-idx;
                res = min(res, window_length);
            }
        }
        
        return res==INT_MAX? 0: res;
    }
};