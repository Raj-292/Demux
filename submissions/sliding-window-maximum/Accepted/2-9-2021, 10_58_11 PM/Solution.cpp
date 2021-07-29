// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Keep the index
        deque<int> dq;
        int active_window = 0;
        
        vector<int> res;
        int i, n = nums.size();
        for(i = 0; i < n; i++) {
            // Remove smaller numbers from the back
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            // Remove the stale indices from the front
            while(!dq.empty() && dq.front() < active_window)
                dq.pop_front();
            
            dq.push_back(i);
            
            if(i >= k-1) {
                res.push_back(nums[dq.front()]);
                active_window++;
            }
        }
        
        return res;
    }
};