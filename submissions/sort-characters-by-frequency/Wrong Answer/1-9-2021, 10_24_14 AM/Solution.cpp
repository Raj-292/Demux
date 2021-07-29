// https://leetcode.com/problems/sort-characters-by-frequency


class Solution {
public:
   
    string frequencySort(string s) {
       vector<char> v(256,0);
        for(auto x:v) {
            v[x]++;
        }
        sort(s.begin(), s.end(), [=] (char a, char b) {
            if(v[a]==v[b]) return a<b;
            return v[a]>v[b];
        });
        return s;
        
    }
};