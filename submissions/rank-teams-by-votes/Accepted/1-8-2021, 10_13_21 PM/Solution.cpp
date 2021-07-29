// https://leetcode.com/problems/rank-teams-by-votes

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // Rank matrix -> rank[i][j] tell us the # of times team i has been ranked at jth position (j class votes)
        // Rank -> 26 * # of teams
        // n - # of voters 
        int n = votes.size();
        // m - # of teams
        int m = votes[0].size();
        vector<vector<int> > rank(26, vector<int>(m,0));
        
        // traverse through no. of voters
        for(int i=0;i<n;i++){
            // traverse through no. of teams
            for(int j =0;j<m;j++){
                rank[votes[i][j]-'A'][j]++;
            }
        }
        // 
        
        // take any configuration of team
        string res = votes[0];
        sort(res.begin(),res.end(),[=](char teamA,char teamB){
            for(int i=0;i<m;i++){
                // i -> class votes
                if(rank[teamA-'A'][i]==rank[teamB-'A'][i]) continue;
                else return rank[teamA-'A'][i]>rank[teamB-'A'][i];
            }
            return teamA<teamB;
        });
        return res;
        
    }
};