// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res="";
        long long int i, n, q, d, rem=0;
        
        vector<string> v;
        unordered_map<int, int> umap;
       
        
        q = numerator/denominator;
        rem = numerator%denominator;
        
        res+= to_string(q);
       
        if(rem ==0 )
            return res;
        else
            res+='.';
        
       
        
        while(rem>0)
        {
            if(umap.find(rem) == umap.end())
            {
                umap[rem] = res.size();
                
                rem*=10;
                q = rem/denominator;
                rem = rem%denominator;
                res+= to_string(q);
            }
            else
            {
                res = res.substr(0, umap[rem]) + "(" + res.substr(umap[rem],  res.size() - umap[rem]) + ")";
                break;
            }
        }
        cout<<res;
        // cout<<(2%3);
        return res;
    }
};