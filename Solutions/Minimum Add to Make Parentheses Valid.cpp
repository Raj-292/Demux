class Solution {
public:
    int minAddToMakeValid(string S) {
        int n = S.size(), i, count = 0, res = 0;

        for (i = 0; i < n; i++) {
            if (S[i] == '(')
                count++;
            else {
                if (count > 0)
                    count--;
                else {
                    res++;
                    // Can skip the below line
                    count = 0;
                }
            }
        }

        res += count;

        return res;
    }
};