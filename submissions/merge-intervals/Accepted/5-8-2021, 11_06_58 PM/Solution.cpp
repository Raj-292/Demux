// https://leetcode.com/problems/merge-intervals

typedef vector<int> vit;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort w.r.t start time
        sort(intervals.begin(),intervals.end(),[](vit a,vit b){
           return a[0]<b[0]; 
        });
        
        // iterate through intevals
        int n = intervals.size();
        vector<vit> res;
        vit prev = intervals[0];
        
        // start merging intervals
        for(int i=1;i<n;i++){
            vit curr = intervals[i];
            // if there is a overlap
            if(prev[1]>=curr[0]){
                // update the endtime of current
                prev[1]=max(prev[1],curr[1]);
            } else{
                res.push_back(prev);
                prev = curr;
            }
        }
        // push the last interval
        res.push_back(prev);
        return res;
    }
};