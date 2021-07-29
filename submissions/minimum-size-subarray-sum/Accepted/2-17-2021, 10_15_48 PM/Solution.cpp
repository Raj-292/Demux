// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), i, cum_sum = 0, window_length, res = INT_MAX;
        // Key is the prefix sum
        // Value is the index
        map<int, int> m;
        
        // Empty prefix
        m[0] = -1;
        
        for(i = 0; i < n; i++) {
            cum_sum += nums[i];
            
            // Largest history with prefix sum <= cum_sum-target
            // UB-1
            // UB
            auto it = m.upper_bound(cum_sum-target);
            
            // UB-1
            if(it == m.begin()){
                m[cum_sum] = i;
                continue;
            }
            else{
                --it;
                window_length = i-it->second;
                res = min(res, window_length);
            }
            
            m[cum_sum] = i;
        }
        
        return res==INT_MAX? 0: res;
    }
};