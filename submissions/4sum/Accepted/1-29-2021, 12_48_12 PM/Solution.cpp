// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        set<vector<int>> res;
        if(nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        int p1=0, p2=0, p3=0, p4=0, px=0, py=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            p1=nums[i];
            for(int j=i+1; j<n; j++)
            {
                p2=nums[j];
                p3=j+1;
                p4=n-1;
                
               while(p3<p4){
                px=nums[p3];
                py=nums[p4];
                //if sum is equal to zero 
                if(p1+p2+px+py==target)
                {
                    res.insert(vector<int>{p1,p2,px,py});
                    //increment j skipping the duplicate values
                    while(p3<p4 && px==nums[p3]) p3++;
                    //decrement k skipping the duplicate        awdrgvalues
                    while(p3<p4 && py==nums[p4]) p4--;
                    
                    
                }
                else
                    if(p1+p2+px+py>target) p4--;
                    else p3++;
            }
            }
        }
        for(auto c:res)
            result.push_back(c);
        return result;
    }
};