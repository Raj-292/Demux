string s;

bool compare(char a, char b) {
	// check the relative ordering of a and b in string S
	return s.find(a) < s.find(b);
}

class Solution {
public:

	string customSortString(string S, string T) {
		s = S;
		sort(T.begin(), T.end(), compare);
		return T;
	}
};

// This will work too:

string s;

class Solution {
public:
	static bool compare(char a, char b) {
		// check the relative ordering of a and b in string S
		return s.find(a) < s.find(b);
	}
	string customSortString(string S, string T) {
		s = S;
		sort(T.begin(), T.end(), compare);
		return T;
	}
};