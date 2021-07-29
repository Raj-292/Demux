// https://leetcode.com/problems/prison-cells-after-n-days

class Solution {
public:
    string getNextConfig(string &curr_config) {
        string next_config(8, '0');
        next_config[0] = next_config[7] = '0';
        
        for(int i = 1; i < 7; i++) {
            next_config[i] = curr_config[i-1] == curr_config[i+1]? '1': '0';
        }
        
        return next_config;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // Key - configuration
        // Value - Iteration count when it occured for the first time
        unordered_map<string, int> m;
        vector<string> conf;
        
        int i;
        string init_config(8, '0');
        
        for(i = 0; i < 8; i++)
            init_config[i] = cells[i]+'0';
        
        string curr_config = init_config, next_config, res;
        // Day 0
        m[init_config] = 0;
        conf.push_back(init_config);
        
        // Loop runs atmost 256 times
        for(i = 1; i <= N; i++) {
            next_config = getNextConfig(curr_config);
            
            // Cycle
            if(m.find(next_config) != m.end())
                break;
            
            // Not a cycle
            // Insert in the map
            m[next_config] = i;
            
            // Push in the vector
            conf.push_back(next_config);
            
            // Update current config
            curr_config = next_config;
        }
        
        if(i == N+1)
            res = next_config;    
        else {
            // Find the cycle length
            int cycle_length = i - m[next_config];
            int tail_length = m[next_config];
            
            int j = (N-tail_length)%cycle_length;
            
            res = conf[tail_length+j];
        }
        
        // Get vector from the string
        vector<int> ans(8);
        
        for(int i = 0; i < 8; i++)
            ans[i] = res[i]-'0';
        
        return ans;
    }
};