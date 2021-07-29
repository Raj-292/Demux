// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
            int head=0,minLength=INT_MAX;
        for(char c:t)hash[c]++;
        int count=0;
        int p1=0,p2=0;
        while(p2<s.size()){
            //adding logic
            if(hash[s[p2]]>0) count++;
            hash[s[p2]]--;
            p2++;
            
            //exist logic
            while(count==t.size())
            {
                if(p2-p1<minLength)
                {
                    minLength=p2-p1;
                    head=p1;

                }
            
            //removal criteria
            if(hash[s[p1]]==0)count--;
            hash[s[p1]]++;
            p1++;

}
    }
        if(minLength==INT_MAX)return" ";
        else
            return s.substr(head,minLength);

        }
        
    
};