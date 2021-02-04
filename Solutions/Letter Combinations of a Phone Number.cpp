My sol:

class Solution {
public:

	string digitMap(int x) {
		vector<string> v(10, "");
		v[2] = "abc";
		v[3] = "def";
		v[4] = "ghi";
		v[5] = "jkl";
		v[6] = "mno";
		v[7] = "pqrs";
		v[8] = "tuv";
		v[9] = "wxyz";

		return v[x];
	}

	void f(string nums, int pos, string contri, vector<string> &res) {

		//base case

		if (nums.size() == 0) {
			return;
		}

		if (pos == nums.size()) {
			res.push_back(contri);
			return;
		}

		//recursive case
		for (const char& x : digitMap(nums[pos] - '0') ) {
			string contri1 = contri;
			contri1 += x; //contri is one of the alphabets of the key
			f(nums, pos + 1, contri1, res);
		}
	}

	vector<string> letterCombinations(string digits) {
		string contri = "";
		vector<string> res;
		f(digits, 0, contri, res);

		return res;
	}
};

My sol Method 1 (i.e combining at parent)

class Solution {
public:

	string digitMap(int x) {
		vector<string> v(10, "");
		v[2] = "abc";
		v[3] = "def";
		v[4] = "ghi";
		v[5] = "jkl";
		v[6] = "mno";
		v[7] = "pqrs";
		v[8] = "tuv";
		v[9] = "wxyz";

		return v[x];
	}

	vector<string> f(string nums, int pos) {

		if (nums.size() == 0) {
			return {};
		}

		//base case
		if (pos == nums.size()) {
			return {""};
		}

		//recursive step

		//eg. if 3 is pressed, we consider possibliltes {d...},{e...},f{...}

		vector<string> res;

		for (const char& x : digitMap(nums[pos] - '0')) {

			vector<string> c;
			vector<string> c1;
			c = f(nums, pos + 1);

			//append x to all the elts of c
			for (string y : c) {
				y = x + y;
				c1.push_back(y);
			}

			//adding all these elements to res;
			for (auto y : c1) {
				res.push_back(y);
			}
		}

		return res;
	}

	vector<string> letterCombinations(string digits) {
		return f(digits, 0);
	}
};



