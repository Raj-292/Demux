class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //take a number c=0 and set the bits according seeing the counrt of 1s and dividing cnt by 3 bitwise
        int c = 0;
        vector<int> cntof1(32, 0);
        int p;
        int ai;
        for (int i = 0; i < 32; i++)
        {   p = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                ai = (1 << i)&nums[j];
                if (ai)
                    p++;
            }
            if (p % 3 != 0)
                c = c | (1 << i);
        }
        return c;
    }
};