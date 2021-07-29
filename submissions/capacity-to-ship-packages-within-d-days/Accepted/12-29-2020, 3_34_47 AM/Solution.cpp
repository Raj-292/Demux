// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int rtt(vector<int>& weights, int C) {
        int sum_weights = 0, ans = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            if(sum_weights+weights[i] <= C)
                sum_weights += weights[i];
            else {
                ans++;
                sum_weights = weights[i];
            }
        }
        
        return ++ans;       
    }
    int shipWithinDays(vector<int>& weights, int D) {
        // FFFTTT
        // local variables <-- underscore max_elt
        // class functions <-- camel case shipWithin
        // class variables <-- underscore (trailing underscore) max_elt_
        int max_element = INT_MIN, sum_element = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            max_element = max(max_element, weights[i]);
            sum_element += weights[i];
        }
        
        // FFFTTT
        // p(x): rtt <= D
        // First T
        int lo = max_element, hi = sum_element, mid;
        
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            
            if(rtt(weights, mid) <= D)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return lo;
    }
};