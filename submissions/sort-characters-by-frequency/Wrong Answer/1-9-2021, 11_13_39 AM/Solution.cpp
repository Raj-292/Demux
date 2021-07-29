// https://leetcode.com/problems/sort-characters-by-frequency


class Solution {
public:
   
    string frequencySort(string s) {
       vector<char> v(256,0);
        for(int i=0; i<s.size(); i++) {
            v[s[i]]++;
        }
        // for(auto x:v) {
        //     cout<<v[x]<<" ";
        // }
        sort(s.begin(), s.end(), [=] (char a, char b) {
           if(v[a]==v[b]) return a<b;
            return v[a]>v[b];
        });
        return s;
        
    }
};