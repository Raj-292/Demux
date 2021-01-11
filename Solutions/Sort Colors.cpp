class Solution {
public:
    void sortColors(vector<int>& nums) {
        // counting sort
        // create a map of 3 and initialize b 0
        vector<int> v(3, 0);
        for (auto i : nums) v[i]++;

        int j = 0;
        for (int i = 0; i < 3; i++) {
            while (v[i] != 0) {
                nums[j++] = i;
                v[i]--;
            }
        }
    }
};

// Better Solution using 2 pointers

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // counting sort
        // create a map of 3 and initialize b 0
//         vector<int> v(3,0);
//         for(auto i: nums) v[i]++;

//         int j =0;
//         for(int i=0;i<3;i++){
//             while(v[i]!=0){
//                 nums[j++]=i;
//                 v[i]--;
//             }
//         }

        // 2 pointers
        int red = 0;
        int white = 0; // running pointer
        int blue = nums.size() - 1;

        while (white <= blue) {
            if (nums[white] == 0) {
                swap(nums[white++], nums[red++]);
            } else if (nums[white] == 2) {
                swap(nums[white], nums[blue--]);
            } else white++;
        }

    }
};