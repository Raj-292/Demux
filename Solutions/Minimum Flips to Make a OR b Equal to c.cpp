class Solution {
public:
    int minFlips(int a, int b, int c) {
        // Iterate bit by bit
        int i, ai, bi, ci, res = 0;

        for (i = 0; i < 32; i++) {
            ai = (1 << i)&a;
            bi = (1 << i)&b;
            ci = (1 << i)&c;

            if ((ai | bi) == ci)
                continue;

            if ((ai & bi) > 0)
                res += 2;
            else
                res++;
        }

        return res;

    }
};