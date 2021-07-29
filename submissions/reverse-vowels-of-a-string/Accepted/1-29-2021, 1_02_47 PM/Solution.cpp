// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        if(s.size()==0 || s.size()==1) return s;
        int p1=0; 
        int p2=s.size()-1;
        vector<int> hash(256, 0);
        hash['A']=1;
        hash['a']=1;
        hash['E']=1;
        hash['e']=1;
        hash['i']=1;
        hash['I']=1;
        hash['O']=1;
        hash['o']=1;
        hash['u']=1;
        hash['U']=1;
        while(p1<p2)
        {
            if(hash[s[p1]]>0 && hash[s[p2]]>0){
                swap(s[p1], s[p2]);
                p1++; p2--;
            }
            if(hash[s[p1]]==0)
                p1++;
            if(hash[s[p2]]==0)
                p2--;
            
        }
        return s;
    }
};