// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    
    int f(int n, int pos,vector<int>& visited){

        if(pos>n)
            return 0;
        
        if(pos==n)
            return 1;
        
        int s1 = 0;
        int s2 = f(n,pos+2,visited);
        
        if(visited[pos+1]==-1){
            s1 = f(n,pos+1,visited);
            visited[pos+1] = s1;
        } else{
            s1 = visited[pos+1];
        }
        
        // if(visited[pos+2]==-1){
        //     s2 = f(n,pos+2,visited);
        //     visited[pos+2] = s2;
        // } else{
        //     s2 = visited[pos+2];
        // } 
        
        return s1 + s2 ;
        
    }
    int climbStairs(int n) {
        vector<int> visited(50,-1);
        return f(n,0,visited);
    }
};