// https://leetcode.com/problems/sort-characters-by-frequency

vector<int> v(256,0);
class Solution {
public:
   
    static bool campare(char a, char b)  {
           if(v[a]==v[b]) return a<b;
            return v[a]>v[b];
        }
    string frequencySort(string s) {
       
        for(int i=0; i<s.size(); i++) {
            v[s[i]]++;
        }
        // for(auto x:v) {
        //     cout<<v[x]<<" ";
        // }
        sort(s.begin(), s.end(), campare);
        return s;
        
    }
};