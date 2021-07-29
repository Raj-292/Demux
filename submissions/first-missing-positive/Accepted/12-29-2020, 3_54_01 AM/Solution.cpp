// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), k, i, j;
        
        // Moving unwanted numbers to the end of the array
        i = 0, j = n-1;
        while(i <= j) {
            if(nums[i] >=1 && nums[i] <= n){
                i++;
                continue;
            }
            // Here means unwanted
            swap(nums[i], nums[j]);
            j--;
        }
        
        // cout << j << endl;
        
        // Mark the numbers
        for(i = 0; i <= j; i++) {
            if(nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
        }
        
        // cout << nums[0] << ", " << nums[1] << ", " << nums[2] << endl;
        
        // find the first positive
        for(i = 0; i <= j; i++) {
            if(nums[i] > 0)
                return i+1;
        }
        
        return i+1;
        
        
    }
};