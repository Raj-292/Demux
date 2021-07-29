// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    typedef vector<int>::iterator vitr;
    int cnt =0;
    
    void merge_sort(vitr start,vitr end){
        if(end-start <=1) return;
        vitr mid = start + (end-start)/2;
        merge_sort(start,mid);
        merge_sort(mid,end);
        // combine
        for(vitr i=start;i<mid;i++){
            for(vitr j=mid;j<end;j++){
                if(*i > 2L* (*j)) cnt++;
            }
        }
        inplace_merge(start,mid,end);
    }
    
    int reversePairs(vector<int>& nums) {
        merge_sort(nums.begin(),nums.end());
        for(int i: nums) cout << i << " ";
        return cnt;
    }
};