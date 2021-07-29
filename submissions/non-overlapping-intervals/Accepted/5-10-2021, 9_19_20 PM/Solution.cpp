// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    typedef vector<int> vit;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort w.r.t end time
        sort(intervals.begin(),intervals.end(),[](vit a,vit b){
           return a[1]<b[1]; 
        });
        // take the first interval
        int n = intervals.size();
        int cnt = 0;
        if(n==0) return 0;
        int end = intervals[0][1];
        // iterate through all other intervals (start with 2nd one)
        for(int i=1;i<n;i++){
            vit v = intervals[i];
            // conflict -> resolve using end first crietria
            // no overlap
            if(end<=v[0]) end = v[1];
            else {
                // overlap
                end = min(v[1],end);
                cnt++;
            }
        }
        return cnt;
    }
};