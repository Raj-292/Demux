// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int j=0;
        char x;
        char y;
        vector<pair<int, string> >v;
        sort(d.begin(), d.end());
        
        for(auto c: d){
            j=0;
            for(int i=0; i<s.size(); i++){
                if(c[j]==s[i])
                    j++;
            }
           
            if(j==c.size()){
                string pu=to_string(j)+"#"+c;
                v.push_back({j, c});
              
            }
        }
       sort(v.begin(), v.end(), [=](pair<int, string> &p1, pair<int, string> &p2){
          if(p1.first==p2.first)
              return p1.second<p2.second;
           
           return p1.first>p2.first;
       });
        
        if(v.size()==0)
            return "";
        string kj=v[0].second;
       return kj;
    }
};