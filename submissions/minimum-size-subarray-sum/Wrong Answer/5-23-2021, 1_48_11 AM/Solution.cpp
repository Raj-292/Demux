// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int binarytree(vector<int> & prefix_sum,int target)
    {
        int n=prefix_sum.size();
        int lo=0,hi=n-1,mid;
        while(lo<hi)
        {
            mid=lo+(hi-lo+1)/2;
            if(prefix_sum[mid]>target)
            {
                hi=mid-1;
            }
            else
            {
                lo=mid;
            }
        }
        if(prefix_sum[lo]<=target)
        {
            return lo;
        }
        return -1;
    }
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        vector<int> prefix_sum;
         prefix_sum.push_back(0);
        int cum_sum=0, window_length, res = INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cum_sum+=nums[i];
            prefix_sum.push_back(cum_sum);
            
            int idx=binarytree(prefix_sum,cum_sum-target);
            
            if (idx=-1)
            {
                continue;
            }
            else
            {
                window_length = i-idx+1;
                res = min(res, window_length);
            }
            
        }
                return res==INT_MAX? 0: res;
    }
};