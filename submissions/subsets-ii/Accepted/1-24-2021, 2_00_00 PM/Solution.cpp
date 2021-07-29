// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    int count=0;
    void f(vector<int>& nums, int i, int end, vector<int> contri, vector<vector<int>>& res){
        count=0;
        
        if(i==end){
            for(auto c: res){
                if(c==contri)
                 count=1;
            }
            
            if(count==0)
            res.push_back(contri);
            
            contri.push_back(nums[end]);
            
            count=0;
            for(auto c: res){
                if(c==contri)
                 count=1;
            }
            
            if(count==0)
                res.push_back(contri);
            
            return;
        }
        
        else{
            f(nums, i+1, end, contri, res);
            contri.push_back(nums[i]);
            f(nums, i+1, end, contri, res);
            contri.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        //vector<int> contri{};
        f(nums, 0, nums.size()-1, {}, res);
        return res;
    }
};