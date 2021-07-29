// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& contri, int start){
        //Base
        if(start==nums.size()){
            ans.push_back(contri);
            return;
        }
        
        // Recusrsion
        int j=start;
        while(j<nums.size() && nums[j] == nums[start])
            j++;
        
        f(nums, ans, contri, j);
        contri.push_back(nums[start]);
        f(nums, ans, contri, start+1);
        contri.pop_back();
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> contri;
        f(nums, ans,contri,0);
        return ans;
    }
};