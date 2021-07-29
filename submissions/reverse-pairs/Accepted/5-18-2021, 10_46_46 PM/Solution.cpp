// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    int res;
     typedef vector<int> :: iterator vitr;
    void qs( vitr start,vitr end)
    {
        if(end-start<=1)return;
        vitr mid=start+(end-start)/2;
        qs(start,mid);
        qs(mid,end);
        // condition
        for(vitr i=mid;i<end;i++)
        {
            int t=(mid-upper_bound(start,mid,2L*(*i)));
            if(t==0)
                break;
            res=res+t;
        }
        
        inplace_merge(start,mid,end);
    }
    int reversePairs(vector<int>& nums) 
    {
        res=0;
        qs(nums.begin(),nums.end());
       
        return res;
    }
};