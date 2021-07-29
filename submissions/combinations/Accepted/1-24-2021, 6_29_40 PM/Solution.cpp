// https://leetcode.com/problems/combinations

class Solution {
public:
    void f(int k, int n, vector<int>& contri, vector<vector<int>>& res, int start){
        if(k==0){
            cout<<"yes";
            res.push_back(contri);
            return;
        }
        if(start>n){
             //res.push_back(contri);
            return;}
        
        f(k, n, contri, res, start+1);
        
        contri.push_back(start);
        f(k-1, n, contri, res, start+1);
       
        contri.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> contri;
        f(k, n, contri, res, 1);
        for(auto x: res){
            for(auto y:x)
                cout<<y;
        }
        return res;
    }
};