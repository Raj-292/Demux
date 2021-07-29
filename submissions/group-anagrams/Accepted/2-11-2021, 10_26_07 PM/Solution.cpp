// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    string getGroupId(string &s) {
        vector<int> freq(26, 0);
        
        for(auto &ch : s) {
            freq[ch-'a']++;
        }
        
        string res = "";
        for(int i = 0; i < 26; i++) {
            res = res + to_string(freq[i]) + "#";
        }
        
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        
        int i;
        for (i = 0; i < strs.size(); i++) {
            // Let's get the group identifier
            string id = getGroupId(strs[i]);
            
            // If this is the first element of the group
            if(m.find(id) == m.end()) {
                m[id] = res.size();    
                res.push_back({});
                
            }
            res[m[id]].push_back(strs[i]);
        }
        
        return res;
    }
};