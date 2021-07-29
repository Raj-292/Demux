// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int S(vector<int>& nums, int d) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += ceil((float)nums[i]/d);
        }
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        // FFFTTTTT
        // first T
        // p(x): S(x) <= threshold
        int maxE = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
            maxE = max(maxE, nums[i]);
        
        int lo = 1, hi = maxE, mid;
        
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            
            if(S(nums, mid) <= threshold)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return lo;
    }
};