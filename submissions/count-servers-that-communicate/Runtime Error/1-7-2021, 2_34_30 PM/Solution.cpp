// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<pair<int, int> >v{};
        int n=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    v.push_back(make_pair(i, j));

            }
        }
        n=v.size();
        int ans{};
        int x;
        int y;
        int z;
        for(auto c:v)
            cout<<c.first<<" "<<c.second<<endl;
        set<pair<int, int> >s{};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
            if(v[i].first==v[j].first && i!=j)
            {
             x=v[i].first;
             y=v[i].second;
             z=v[j].second; 
                s.insert(make_pair(x, y));
                s.insert(make_pair(x, z));
                
            } 
             if(v[i].second==v[j].second && i!=j)
            {
             x=v[i].first;
             y=v[i].first;
             z=v[j].second; 
                s.insert(make_pair(x, z));
                s.insert(make_pair(y, z));
                
            } 
            }
        }
        ans=s.size();
        return ans;
    }
    
};