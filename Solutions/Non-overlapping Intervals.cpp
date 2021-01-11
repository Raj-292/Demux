class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort w.r.t. end time
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        });


        int cnt = 0;
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            } else cnt++;
        }
        return cnt;
    }
};