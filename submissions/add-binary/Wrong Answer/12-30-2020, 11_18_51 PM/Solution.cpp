// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int x=a.size()-1,y=b.size()-1;
        int carry=0;
        string ans;
        while(x>=0 && y>=0){
            int sum=a[x]-'0'+b[y]-'0'+carry;
            if(sum==2) {ans+='0'; carry=1;}
            else if(sum==0){ ans+='0'; carry=0;}
            else if(sum==1){ans+='1';carry=0;}
            x--,y--;
        }
        if(x>=0){
            int sum=a[x]-'0'+carry;
            if(sum==2) {ans+='0'; carry=1;}
            else if(sum==0){ ans+='0'; carry=0;}
            else if(sum==1){ans+='1';carry=0;}
            x--;
        }
         if(y>=0){
            int sum=b[y]-'0'+carry;
            if(sum==2) {ans+='0'; carry=1;}
            else if(sum==0){ ans+='0'; carry=0;}
            else if(sum==1){ans+='1';carry=0;}
            y--;
        }
        if(carry==1)ans+='1';
     reverse(ans.begin(),ans.end());
        return ans;
    }
};