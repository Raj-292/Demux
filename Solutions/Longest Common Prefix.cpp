class Solution {
public:
    bool isSame(vector<string> &strs, char ch, int pos) {
        int i;

        for (i = 0; i < strs.size(); i++)
            if (strs[i][pos] != ch) return false;

        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int i, n = INT_MAX;
        string lcp = "";

        if (strs.size() == 0) return lcp;

        for (i = 0; i < strs.size(); i++)
            n = min(n, (int)(strs[i].size()));

        for (i = 0; i < n; i++) {

            if (!isSame(strs, strs[0][i], i)) break;

            lcp += strs[0][i];
        }

        return lcp;
    }
};