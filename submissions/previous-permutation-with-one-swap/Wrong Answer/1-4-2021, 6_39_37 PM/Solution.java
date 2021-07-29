// https://leetcode.com/problems/previous-permutation-with-one-swap

class Solution {
    public int[] prevPermOpt1(int[] arr) {
        
       
       int a=0;
       int max=0;
        int maxn=0;
       for(int i=arr.length-1; i>=0; i--)
       {
           for(int j=i-1; j>=0; j--)
           {
                if(arr[j]>arr[i])
                {
                    if(arr[i]!=arr[i-1])
                    {
                        a=arr[i];
                        arr[i]=arr[j];
                        arr[j]=a;
                        return arr;
                    }
                    
                }
           }
            
           
        }
        return arr;
        
        
    }
}