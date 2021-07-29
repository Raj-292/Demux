// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    typedef vector<pair<int,int>>::iterator pit;
    vector<int> res;
    
    void merge_sort(pit start,pit end){
        if(end-start <=1) return;
        pit mid = start + (end-start)/2;
        merge_sort(start,mid);
        merge_sort(mid,end);
        for(pit i=start,j=mid;i<mid;i++){
            while(j<end && i->first > j->first) j++;
            res[i->second]+=(j-mid);
        }
        inplace_merge(start,mid,end);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
            res.push_back(0);
        }
        merge_sort(temp.begin(),temp.end());
        return res;
    }
};