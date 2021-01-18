class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort w.r.t. end time
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        });

        // count no. of non-overlapping jobs
        int cnt = 0;
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            // check the start time of next job
            if (intervals[i][0] >= end) {
                // modify the end time
                end = intervals[i][1];
            } else cnt++;
        }
        return cnt;
    }
};