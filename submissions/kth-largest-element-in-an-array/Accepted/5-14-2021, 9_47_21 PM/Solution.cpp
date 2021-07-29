// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Max Heap
        // SC : O(n)
        priority_queue<int> maxq(nums.begin(),nums.end());
        while(--k) maxq.pop();
        return maxq.top();
        // Min Heap
        // pririty_queue<int,vector<int>,greater<int>> minq;
        
    }
};