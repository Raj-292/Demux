// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //hashmap
        vector<int>hash(256,0);

        //freq array
        for(char c:p) hash[c]++;
        vector<int>res;
        
        int p1=0,p2=0,count=p.size();
        while(p2<s.size())
        {
            //logic while adding the elt
            if(hash[s[p2]]>0)count--;
            hash[s[p2]]--;
            p2++;
            //exit criteria count==0
            
            if(count==0) res.push_back(p1);
            //logic of removing elt
            if(p2-p1==p.size()){
                if(hash[s[p1]]>=0)count++;
                hash[s[p1]]++;
                p1++;
                
            }
                

        }
        return res;
        
    }
};