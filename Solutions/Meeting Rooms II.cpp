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


// My sol:
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;

        int max_cnt = 0;

        for (auto x : intervals) {
            times.push_back({x[0], 1});
            times.push_back({x[1], -1});

        }

        sort(times.begin(), times.end(), [](pair<int, int> x, pair<int, int> y) {
            if (x.first == y.first) {
                return x.second < y.second;
            }
            return  x.first < y.first;
        });                                   //This whole thing can be replaced simply by sort(times.begin(),times.end())

        int cnt = 0;

        for (auto x : times) {
            cnt += x.second;
            max_cnt = max(max_cnt, cnt);
        }

        return max_cnt;
    }
};

Runtime: 16 ms, faster than 100.00 % of C++ online submissions for Meeting Rooms II.
Memory Usage : 12.6 MB, less than 50.09 % of C++ online submissions for Meeting Rooms II.