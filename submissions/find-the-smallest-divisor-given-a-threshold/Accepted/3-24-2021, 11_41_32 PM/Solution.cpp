// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int divi(vector<int>& nums, int n){
        int k=0;
        for(int i=0;i<nums.size();i++){
            k = k + ceil((float)nums[i]/n);
        }
        return k;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1,hi=INT_MIN,mid,k;
        for(int i=0;i<nums.size();i++){
            hi = max(nums[i],hi);
        }
        
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            k = divi(nums, mid);
            if(k <= threshold)
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
        
    }
};