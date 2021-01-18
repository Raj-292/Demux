class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        // Sort this heightwise
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) return a[0] > b[0];

            return a[1] < b[1];
        });

        vector<vector<int>> res(people.size());
        int j;

        for (int i = 0; i < people.size(); i++) {
            // Put this person at the right slot and shift everything
            int slot = people[i][1];
            for (j = i; j > slot; j--)
                res[j] = res[j - 1];

            res[slot] = people[i];
        }

        return res;
    }
};