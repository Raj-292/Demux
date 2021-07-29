// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target

class Solution {
public:
    int sum(vector<int> arr,int val){     
        
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=val)
                arr[i]=val;
        }
        int arsum=0;
        for(int i=0;i<n;i++)
            arsum+=arr[i];
        
        return arsum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size(),lo,mid,hi;
      
        int maxval=INT_MIN;
                
        for(int i=0;i<n;i++)
            maxval=max(maxval,arr[i]);        
        
        lo=0,hi=maxval;
        
        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(sum(arr,mid)<=target)
                lo=mid;
            else
                hi=mid-1;
        }

        int s1=abs(sum(arr,lo)-target);
        int s2=abs(sum(arr,lo+1)-target);
        return (s1<=s2?lo: lo+1);
            
        
    }
};