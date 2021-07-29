#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//check whether chars can be appended to strings

	vector<string> v1 = {"abc", "def", "ghi"};

	for (auto x : v1) {
		cout << x << " ";
	}

	// cout << endl;

	// char c1 = '1';

	// // v1[1] = c1 + v1[1];

	// string str = "xyz";


	// // for(char& c : str) {

	// // }

	// for (auto x : v1) {
	// 	cout << x << " ";
	// }

	char c = '$';

	for (string& s : v1) {
		s = c + s;
	}

	for (auto x : v1) {
		cout << x << " ";
	}

}