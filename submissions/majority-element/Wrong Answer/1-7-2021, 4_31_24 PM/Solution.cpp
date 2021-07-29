// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=nums.size(); 
        set<int> s{};
        s.insert(nums[0]);
        int count{1};
        int max{1};
        int se{};
        int max_el{nums[0]};
        for(int i=1; i<n; i++){
        se=s.size();  
        s.insert(nums[i]);
           if(s.size()==se){
               count++;
               if(count>max){
                   max_el=nums[i];
                   max=count;    
                   }
           }
            else{
                count=1;
            }
       } 
        return max_el;
    }
    
}; 