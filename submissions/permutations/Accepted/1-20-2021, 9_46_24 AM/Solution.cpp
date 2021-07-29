// https://leetcode.com/problems/permutations

class Solution {
public:
    void f(vector<int> &nums,vector<bool> visited,vector<int> contri,vector<vector<int>> &res){
        //Base case
        
        int i;
        for(i=0;i<nums.size();i++){
            if(!visited[i]){
                break;
            }
        }
        if(i==nums.size()){
            res.push_back(contri);
            return;
        }
        //Recursive case
        //Iterate over all the elements for current positions
        vector<int> contri2;
        vector<bool> visited2;
        for(i=0;i<nums.size();i++){
            
            if(!visited[i]){
                contri2=contri;
                visited2=visited;
                contri2.push_back(nums[i]);
                visited2[i]=true;
                f(nums,visited2,contri2,res);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> contri;
        vector<bool> visited(nums.size(),false);
        f(nums,visited,contri,res);
        return res;
    }
};