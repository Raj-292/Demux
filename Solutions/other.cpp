#include <bits/stdc++.h>

using namespace std;

#define ll long long


void traverse(int i, int j, vector<vector<int>>& v, int n ) {
	for (int z = j ; z < n; z++) {
		cout << v[z][j];
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<vector<int>> v;

	for (int i = 0; i < n; i++) {
		vector<int> vi;

		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			vi.push_back(x);
		}

		v.push_back(vi);
	}

	// for (int i = 0; i < v.size(); i++) {
	// 	for (int j = 0; j < v[i].size(); j++) {
	// 		cout << v[i][j] << " ";
	// 		if (j == v[i].size() - 1) {
	// 			cout << '\n';
	// 		}
	// 	}
	// }

	int i_min = 0, i_max = n - 1;
	int j_min = 0, j_max = n - 1;

	int i = 0, j = 0;

	while (i <= i_max && j <= j_max) {

		for (int x = j; x < j_max; x++) {
			cout << v[x][j] << " ";
		}
		i++;

		for (int x = i; x < i_max; x++) {
			cout << v[x][j_max] << " ";
		}
		j--;

		for (int x = j; x >= j_min ; x--) {
			cout << v[i_min][x] << " ";
		}
		i--;

		for (int )


		}




}