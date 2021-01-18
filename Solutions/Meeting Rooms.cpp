//Q: Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.


//Ex 1 : Input: intervals = [[0,30],[5,10],[15,20]]
//Output: false

//Ex 2:Input: intervals = [[7,10],[2,4]]
//Output: true

// Constraints:
// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti < endi <= 106

//My sol:
class Solution {
public:
	bool canAttendMeetings(vector<vector<int>>& intervals) {

		vector<vector<int>> v = intervals;

		if (v.size() == 0) {
			return true;
		}

		sort(v.begin(), v.end(), [](vector<int> x, vector<int> y) {
			return x[0] < y[0];
		});

		vector<int> prev = v[0];

		for (int i = 1; i < v.size(); i++) {
			if (v[i][0] < prev[1]) {
				return false;
			}
			else {
				prev = v[i];
			}
		}

		return true;

	}
};

Runtime: 96 ms, faster than 16.31 % of C++ online submissions for Meeting Rooms.
Memory Usage : 28.5 MB, less than 6.85 % of C++ online submissions for Meeting Rooms.

