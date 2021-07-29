// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> offset = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // q[0] = row idx.
        // q[1] = col idx.
        // q[2] = distance.
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> res(m, vector<int>(n, -1));

        // Initialize the q and visited array (res).
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    res[i][j] = 0;
                }
            }
        }

        // Level-order traversal.
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            // Go through the nbrs.
            for (auto& entry : offset) {
                int x = curr[0] + entry[0];
                int y = curr[1] + entry[1];

                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;

                if (res[x][y] == -1) {
                    res[x][y] = curr[2] + 1;
                    q.push({x, y, curr[2] + 1});
                }
            }
        }

        return res;
    }
};

// Approach 2: (Mark visited when popping)

// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> offset = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // q[0] = row idx.
        // q[1] = col idx.
        // q[2] = distance.
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> res(m, vector<int>(n, -1));

        // Initialize the q and visited array (res).
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                }
            }
        }

        // Level-order traversal.
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            if (res[curr[0]][curr[1]] != -1)
                continue;

            res[curr[0]][curr[1]] = curr[2];

            // Go through the nbrs.
            for (auto& entry : offset) {
                int x = curr[0] + entry[0];
                int y = curr[1] + entry[1];

                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;

                if (res[x][y] == -1) {
                    q.push({x, y, curr[2] + 1});
                }
            }
        }

        return res;
    }
};
