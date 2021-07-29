// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    int fact(int n) {
        int i, res = 1;
        for(i = 1; i <= n; i++)
            res = res * i;
        
        return res;
    }
    
    // Returns the pos unvisited number
    // pos = 3 returns the 3rd unvisited number
    int getNumber(vector<int>& visited, int pos, int n) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i]) continue;
            
            count++;
            if(count == pos)
                return i;
        }
        
        // NF - It won't reach here
        return -1;
    }
    
    string getPermutation(int n, int k) {
        // Jai shree ram
        // Jai shree Jesus
        // Jai allah
        // Jai Jinendra
        // chunk_id is 0 based
        int i, chunk_id, pos, curr_digit, copy_n = n;
        string res = "";
        
        vector<int> visited(copy_n+1, 0);
        
        for(i = 1; i <= copy_n; i++) {
            // Get the chunk id
            chunk_id = (k-1)/fact(n-1);
            
            // Get the corresponding digit
            pos = chunk_id+1;
            curr_digit = getNumber(visited, pos, copy_n);
            res = res + to_string(curr_digit);
            
            // Mark this position as visited
            visited[curr_digit] = 1;
            
            // Update n and k
            k = k - (chunk_id*fact(n-1));
            n--;
        }
        
        return res;
    }
};