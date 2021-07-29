// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort by start time
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        int end= intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(end>=intervals[i][0]) {
                intervals[i][0]=intervals[i-1][0];
                intervals[i][1]=max(end, intervals[i][1]);
            }
            else {
                 v.push_back({intervals[i-1][0], intervals[i-1][1]});

            }
            end=intervals[i][1];
        }
        v.push_back({intervals[intervals.size()-1][0], intervals[intervals.size()-1][1]});
        return v;
    }
};