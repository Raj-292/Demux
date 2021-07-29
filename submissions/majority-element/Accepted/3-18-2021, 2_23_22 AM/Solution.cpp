// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> a;
        for(int i=0;i<nums.size();i++){
            if(a.empty()){
                a.push(nums[i]);
            }
            else if(a.top() == nums[i]){
                a.push(nums[i]);
            }
            else{
                a.pop();
            }
        }
        return a.top();
    }
};