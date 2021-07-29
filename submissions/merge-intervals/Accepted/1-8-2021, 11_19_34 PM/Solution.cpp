// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // sort w.r.t start time
        sort(intervals.begin(),intervals.end());
        //      ,[=](vector<int> v1, vector<int> v2){
        //     return v1[0]<v2[0];
        // });
        
        vector<vector<int>> res;
        int n = intervals.size();
        if(n==0) return res;
        // choose the first interval
        vector<int> prev = intervals[0];
        
        // traverse from 2 nd interval
        for(int i=1;i<n;i++){
            // both intervals are non overlapping
            if(intervals[i][0]>prev[1]){
                res.push_back(prev);
                prev = intervals[i];
            } else{
              // if the intervals are overlapping
                // update the endtime
              prev[1] = max(prev[1], intervals[i][1]);
            }
        }
        res.push_back(prev);
        return res;
        
    }
};