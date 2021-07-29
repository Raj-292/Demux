// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<>> minq;
        minq.push(1);
        if(n==0) return 1;
        int cnt =1;
        while(cnt<n){
            int temp = minq.top();
            minq.pop();
            if(temp%2==0){
                minq.push(temp*2);
            } else if(temp%3==0){
                minq.push(temp*2);
                minq.push(temp*3);
            } else{
                minq.push(temp*2);
                minq.push(temp*3);
                minq.push(temp*5);
            }
            cnt++;
        }
        return minq.top();
    }
};