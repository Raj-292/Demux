// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size()-1;
        int x{};
        int y{};
        while(k--)
        {
            x=nums[0];
            
            for(int i=1; i<=n; i++){
                y=nums[i];
                nums[i]=x;
                x=y;
                
            }
            nums[0]=x;
        }
        
    }  
};