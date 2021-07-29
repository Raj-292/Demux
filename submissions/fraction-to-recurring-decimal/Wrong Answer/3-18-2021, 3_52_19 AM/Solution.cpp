// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int n = numerator, d = denominator;
        string ans = "";
        int temp;
        if(n<0 && d < 0){
            n = abs(n);
            d = abs(d);
        }        
        if(n<0 || d < 0){
            ans += "-";
            n = abs(n);
            d = abs(d);
        }
        if(n>=d){
            temp = n/d;
            ans += to_string(temp);
        }
        else{
            ans += to_string(0);
        }
        temp = n%d;
        if(temp==0)
            return ans;
        
        ans = ans + ".";
        n = temp*10;
        // cout<<n;
        unordered_map<int,int> m;
        int i=0;
        vector<int> q;
        while(n!=0 && m.find(n) == m.end()){
            m[n] = i;
            i++;
            if(n<d){
                // ans += to_string(0);
                q.push_back(0);
                n=n*10;
                continue;
            } 
            // ans += to_string(n/d);
            q.push_back(n/d);
            n=(n%d)*10;
        }
        if(n==0){
            for(int i=0;i<q.size();i++)
                ans += to_string(q[i]);
            return ans;
        }
            
        for(int i=0;i<q.size();i++){
            if(i == m[n])
                ans += "(";
            ans += to_string(q[i]);
        }
        ans += ")";
        
        return ans;
    }
};