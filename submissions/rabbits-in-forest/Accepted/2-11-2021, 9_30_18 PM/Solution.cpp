// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        
        for(int i = 0; i < answers.size(); i++)
            m[answers[i]]++;
        
        int count = 0, num_groups;
        // Iterating over a map
        for(auto x : m) {
            num_groups = ceil((float)x.second/(x.first+1));
            
            count += (x.first+1)*num_groups;
        }
        
        return count;
    }
};