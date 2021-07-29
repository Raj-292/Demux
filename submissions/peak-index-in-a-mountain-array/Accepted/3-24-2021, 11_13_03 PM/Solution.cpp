// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo=0,hi=n-1,mid;
        
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid] > arr[mid+1]){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        return lo;
        
    }
};