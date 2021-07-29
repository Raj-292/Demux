// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n = 0, i, j;
        for(i=0;i<32;i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                  if((nums[j]&1<<i)!=0){
                      count++;
                  }
            }
            
            if((count%3)>0){
                n=(n|  1<<i);
            }

        }
        return n;
        
       
        
    }
};