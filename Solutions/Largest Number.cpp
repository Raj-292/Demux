class Solution {
public:
    static bool compare(string a, string b) {
        // default order for ascebding order is a<b
        // descending order is a>b
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {

        // to_string(int) -> string
        // stoi(string) -> int
        vector<string> str;
        // for(int i=0;i<n;i++) -> i is a index
        // for(auto i:nums) -> i is a value
        for (int i : nums) str.push_back(to_string(i));
        // constructor need to be static in nature
        sort(str.begin(), str.end(), compare);

        string res = "";
        // a+b -> concatenate the string
        for (string s : str) res += s;

        // removing all the leading zeroes
        while (res[0] == '0' && res.size() > 1) {
            // erase works on vector and strings both - erase from a range
            // v.erase(start position,end position )
            res.erase(0, 1);
        }

        return res;


    }
};