// https://leetcode.com/problems/permutations

class Solution {
public:
    void f(vector<int>& nums, vector<bool>& visited, vector<int>& contri, vector<vector<int>>& res){
        int i;
        for(i=0; i<nums.size(); i++){
        if(!visited[i])
            break;
        }
        if(i==nums.size()){
            res.push_back(contri);
            return;}
        for(i=0; i<nums.size(); i++){
            if(!visited[i]){
                contri.push_back(nums[i]);
                visited[i]=true;
                f(nums,visited, contri, res);
                contri.pop_back();
                visited[i]=false;
            }
        }
}
   vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;
        vector<int> contri;
        f(nums,visited, contri, res);
        return res;
    }
};
     