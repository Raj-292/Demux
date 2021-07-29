// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size(), i, sum = 0, currSum, reqdSum, count = 0;
        
        for(i = 0; i < n; i++)
            sum += A[i];
        
        if(sum%3)
            return false;
        
        reqdSum = sum/3;
        
        currSum = 0;
        for(i = 0; i < n; i++){
            currSum += A[i];
            if(currSum == reqdSum){
                currSum = 0;
                count++;
            }
        }
        if(count >= 3)
            return true;
        else
            return false;
    }
};