// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        
        int res = 0;
        for(int i = 0; i < answers.size(); i++) {
            if(m[answers[i]] == 0)
                res += answers[i]+1;
                
            m[answers[i]]++;
            
            // Reset step
            if(m[answers[i]] == answers[i]+1)
                m[answers[i]] = 0;
        }
        
        return res;
        
//         for(int i = 0; i < answers.size(); i++)
//             m[answers[i]]++;
        
//         int count = 0, num_groups;
//         // Iterating over a map
//         for(auto x : m) {
//             num_groups = ceil((float)x.second/(x.first+1));
            
//             count += (x.first+1)*num_groups;
//         }
        
//         return count;
    }
};