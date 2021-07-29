// https://leetcode.com/problems/maximum-gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // random numbers 
        // find the max diff between two numbers in sorted format
        // radix sort
        
        // APPEND Leading zeros
        // iterate through max no. of digits
        // k = log(max_element)
        int maxn = *max_element(nums.begin(),nums.end());
        int bit = 1;
        int n = nums.size();
        int aux[n];
        
        // 2126251
        // 8263562
        // 2625250
        // no. of times we need to run the loop
        while(maxn/bit>0){
            // capture the bit - (nums[i]/bit)%10
            int cnt[10] = {0};
            // counting sort logic begings
            for(int i=0;i<n;i++) cnt[(nums[i]/bit)%10]++;
            // implement counting sort
            // cumative sum
            
            // sort the array accoring to that iteration
            
            for(int i=1;i<10;i++) cnt[i]+=cnt[i-1];
            
            // how to put back the numebrs in sorted order for that iteration
            for(int i=n-1;i>=0;i--){
                aux[cnt[(nums[i]/bit)%10]-1] = nums[i];
                cnt[(nums[i]/bit)%10]--;
            }
            // put back the numbers in nums array
            for(int i=0;i<n;i++) nums[i]=aux[i];
            bit = bit*10;
        }
        int res=0;
        for(int i=1;i<n;i++){
            res = max(res,nums[i]-nums[i-1]);
        }
        return res;
       
    }
};