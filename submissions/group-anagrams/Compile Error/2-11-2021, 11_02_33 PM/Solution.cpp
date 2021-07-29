// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    string getGrpId(string &s)
    {
         vector<int> freq(26,0);
        
        for(auto &ch: s)
        {
             freq[ch-'a']++;
        }
        string s="";
        for(int i=0;i<26;i++)
        {
             res=res+to_string(freq[i])+"#";
        }
        return res;
        
    }
     
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
         vector<vector<string>> res;
        unordered_map<string,int> m;
        int i,j,k;
        
        for(i=0;i<strs.size();i++)
        { 
             string id = getGrpId(strs[i]);
            
             if(m.find(id)==m.end())
             {
                  m[id] = res.size();
                 res.push_back({});
             }
            
             res[m[id]].push_back(strs[i]);
        }
        return res;
        
        
        
        
    }
};