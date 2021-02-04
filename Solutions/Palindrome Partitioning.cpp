class Solution {
public:
    bool isPalindrome(string& s) {
        int start = 0, end = s.size() - 1;

        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++; end--;
        }

        return true;
    }
    void f(string& s, int start, vector<string>& contri, vector<vector<string>>& res) {
        // Base case
        if (start == s.size()) {
            res.push_back(contri);
            return;
        }

        // Try all possibilities of putting a partition
        string part;
        for (int j = start; j < s.size(); j++) {
            // s[start...j] is the first partition
            part = s.substr(start, j - start + 1);

            if (!isPalindrome(part))
                continue;

            contri.push_back(part);
            f(s, j + 1, contri, res);
            contri.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> contri;
        vector<vector<string>> res;

        f(s, 0, contri, res);

        return res;
    }
};