// https://leetcode.com/problems/squares-of-a-sorted-array

  bool campare(int a, int b) {
        return abs(a)<abs(b);
    }
class Solution {
public:
   
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end(), campare);
        for(int i=0; i<nums.size(); i++) {
            nums[i]*=nums[i];
        }
        return nums;
    }
};