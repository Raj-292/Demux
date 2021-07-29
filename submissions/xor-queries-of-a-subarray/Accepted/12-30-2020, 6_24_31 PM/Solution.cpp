// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v(arr.size(),0);
        int run_xor=0;
        for(int i = 0; i < arr.size(); i++) {
            run_xor ^= arr[i];
            v[i]=run_xor;
        }
        vector<int> res;
        for(int i=0 ;i<queries.size(); i++) {
            if(queries[i][0]==0) {
                res.push_back(v[queries[i][1]]);
            }
            else {
                res.push_back(v[queries[i][0]-1]^v[queries[i][1]]);
            }
            
        }
        return res;
    }
};