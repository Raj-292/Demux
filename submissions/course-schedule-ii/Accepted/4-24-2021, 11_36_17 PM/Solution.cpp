// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) 
    {
        int k=p.size();
        map <int,vector <int> > m;
        vector in(n,0);
        for(int i=0;i<k;i++)
        {
            m[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        vector <int> zero_in;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {    
                zero_in.push_back(i);
                //cout<<i<<" ";
            }
            
        }
        //cout<<zero_in[0]<<" ";
        vector <int> res;
        if(zero_in.size()==0)
            return res;
        int index=0;
        k=zero_in.size();
        //cout<<"size: "<<k;
        while(index<zero_in.size())
        {
            res.push_back(zero_in[index]);
            for(auto i:m[zero_in[index]])
            {
                in[i]--;
                if(in[i]==0)
                    zero_in.push_back(i);
            }
            index++;
        }
        return  res.size()==n?res:vector<int>();
        
    }
};