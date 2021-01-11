class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        vector<pair<int, int> > meeting;
        // traverse through intervas
        for (auto it : intervals) {
            // store the startTime,+1
            meeting.push_back({it[0], 1});
            // store the EndTime, -1
            meeting.push_back({it[1], -1});
        }
        // sort w.r.t start time
        sort(meeting.begin(), meeting.end());
        int runningTime = 0;
        int maxTime = 0;
        for (auto it : meeting) {
            // increase/decrease the counter when meeting start/end
            runningTime += it.second;
            maxTime = max(maxTime, runningTime);
        }
        return maxTime;
    }
};