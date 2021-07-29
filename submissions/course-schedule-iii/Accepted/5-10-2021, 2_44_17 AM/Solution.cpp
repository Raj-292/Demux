// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),[=](vector<int> v1,vector<int> v2){
           if(v1[1]==v2[1])
               return v1[0]<v2[0];
            return v1[1]<v2[1];
        });
        int sum=0;
        priority_queue<int> v;
        int count=0;
        int maxx=INT_MIN;
        for(int i=0;i<c.size();i++)
        {
            if(c[i][0]>c[i][1])continue;
            sum+=c[i][0];
            v.push(c[i][0]);
            count++;
            if(sum>c[i][1])
            {
                sum-=v.top();
                v.pop();
                count--;
            }
            maxx=max(maxx,count);
        }
        return maxx==INT_MIN?0:maxx;
    }
};