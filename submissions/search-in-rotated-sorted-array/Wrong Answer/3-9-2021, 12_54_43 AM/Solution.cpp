// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j= nums.size()-1, mid;
        
        while(i<j){
            cout<<i<<" "<<j<<'\n';
            mid = (i+j)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[i]){
                if(target < nums[mid] && target < nums[i]) i = mid+1;
                else j=mid-1;
            }
            else{
                if(target > nums[mid] && target < nums[i]) i = mid+1;
                else j = mid-1;
            }
        }
        if(i< nums.size() && nums[i] == target) return i;
        if(j>=0 && nums[j] == target) return j;
        return -1;
    }
};