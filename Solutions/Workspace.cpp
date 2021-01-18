#include <bits/stdc++.h>
#include "leet.h"

using namespace std;

#define ll long long

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	// sort w.r.t. end time
	int n = intervals.size();
	if (n == 0) return 0;

	sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
		return v1[1] < v2[1];
	});

	//verifying whether the vector is sorted by end times
	for (auto x : intervals) {
		cout << x[0] << " " << x[1] << endl;
	}

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


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> v = take2d();

	// sort(v.begin(), v.end(), [](vector<int> a, vector<int>b) {
	// 	return a[1] < b[1];
	// });

	// for (auto x : v) {
	// 	cout << x[0] << " " << x[1] << endl;
	// }

	int cnt = eraseOverlapIntervals(v);

	cout << "cnt is: " << cnt << endl;


}