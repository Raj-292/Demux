// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    string getGroupId(string& s) {
        vector<int> freq(26, 0);
        
        for(const auto& ch : s) {
            freq[ch-'a']++;
        }
        
        string res = "";
        for(const auto& num : freq) {
            res = res + to_string(num) + "#";
        }
        
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Define history
        vector<vector<string>> res;
        unordered_map<string, int> history;
        
        for (auto& ana : strs) {
            // Get the group id
            string g_id = getGroupId(ana);
            
            // Don't find anything in the map. This is the
            // first element of the group that is being inserted.
            if (history.find(g_id) == history.end()) {
                res.push_back({});
                history[g_id] = (int)res.size()-1;
            }
            
            res[history[g_id]].push_back(ana);
        }
        
        return res;
    }
};