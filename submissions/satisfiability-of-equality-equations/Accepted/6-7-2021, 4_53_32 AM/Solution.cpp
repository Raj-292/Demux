// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
   void dfs(unordered_map<char,vector<char>>&m,unordered_map<char,int>& visited,char start, int label)
   {
       visited[start]=label;
       for(auto &nbr:m[start])
       {
           if(visited.find(nbr)==visited.end())
           {
               dfs(m,visited,nbr,label);
           }
       }    
   }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,vector<char>>m;
        unordered_map<char,int>visited;
      /*   for(auto &eqn: equations)
        {   
           if(eqn[0]==eqn[3])  
          {
            if(eqn[1]=='!')
            {
               return false;
            }
          }
        } */
        
        for(auto &eqn: equations)
        {      
          if(eqn[1]=='=' && eqn[2]=='=')
          {
              m[eqn[0]].push_back(eqn[3]);
              m[eqn[3]].push_back(eqn[0]);
          }
        }
       int  label=0;
        for(auto &node:m)
        {
            if(visited.find(node.first)==visited.end())
            {
                dfs(m,visited,node.first,label);
                label++;
            }
        }
        
        for(auto &eqn:equations)
        {
            if(eqn[1]=='!')
            {
                if(eqn[0]==eqn[3] || (visited.find(eqn[0]) != visited.end() &&
                    visited.find(eqn[3]) != visited.end() && 
                    visited[eqn[0]] == visited[eqn[3]]))
                {
                    return false;
                }
            }
        }         
        return true;
    }
};