// https://leetcode.com/problems/prison-cells-after-n-days

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        string prev="",curr;
        int i,l=cells.size(),itr;
        
        vector<int> res;
        vector<string> pos;
        unordered_map<string,int> configs;
        
        for(i=0;i<l;i++)
            prev+=cells[i]==0?'0':'1';
        
        curr=prev;
        curr[0]=curr[7]='0';
        configs[prev]=0,pos.push_back(prev);
        
        for(i=1;i<=n;i++){
            for(itr=1;itr<7;itr++)
                curr[itr]=(prev[itr-1]==prev[itr+1])?'1':'0';
            if(configs.find(curr)!=configs.end())       //CYCLE
                break;
            configs[curr]=i,pos.push_back(curr);
            prev=curr;
        }
        if(i==n+1)
            for(itr=0;itr<8;itr++)
                res.push_back(curr[itr]=='0'?0:1);
        else{
            int tail_length=configs[curr],cycle_length=i-tail_length;
            i=tail_length+(n-tail_length)%(cycle_length);
            for(itr=0;itr<8;itr++)
                res.push_back(pos[i][itr]=='0'?0:1);
        }
        return res;
    }
};