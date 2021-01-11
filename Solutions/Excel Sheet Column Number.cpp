class Solution {
public:
	int titleToNumber(string s) {
		int n = s.size(), i, num = 0;
		long long int p = 1;

		for (i = n - 1; i >= 0; i--) {
			num += (s[i] - 'A' + 1) * p;
			p *= 26;
		}

		return num;
	}
};