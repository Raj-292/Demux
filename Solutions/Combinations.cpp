class Solution {
public:
    vector<vector<int>> f(int start, int end, int k) {
        // Base step


//         if(k == 0)
//             return {{}};

//         if(start > end)
//             return {};


        if (start > end) {
            // Empty solution
            if (k == 0) return {{}};
            // No solution
            return {};
        }

        if (k == 0)
            return {{}};

        // Recursive step
        // C2
        // Doesn't include the first element
        vector<vector<int>> c2 = f(start + 1, end, k);

        // C1
        // Includes the first element
        vector<vector<int>> temp = f(start + 1, end, k - 1);

        // Append the first element
        vector<vector<int>> c1 = temp;
        for (int i = 0; i < temp.size(); i++)
            c1[i].push_back(start + 1);

        // Merge
        // Res is c1Uc2
        vector<vector<int>> res = c2;
        for (int i = 0; i < c1.size(); i++)
            res.push_back(c1[i]);

        return res;
    }
    vector<vector<int>> combine(int n, int k) {
        return f(0, n - 1, k);
    }
};