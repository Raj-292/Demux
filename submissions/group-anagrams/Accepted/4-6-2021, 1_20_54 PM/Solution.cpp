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
        unordered_map<string, vector<string>> history;
        
        for (auto& ana : strs) {
            // Get the group id
            string g_id = getGroupId(ana);
            history[g_id].push_back(ana);
        }
        
        // Convert this hash map to a vector of vectors.
        vector<vector<string>> res;
        for (auto& entry : history) {
            res.push_back(entry.second);
        }
        
        return res;
    }
};