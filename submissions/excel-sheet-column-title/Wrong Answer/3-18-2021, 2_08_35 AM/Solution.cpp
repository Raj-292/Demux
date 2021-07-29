// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    void f(int num, string& ans){
        if(num==0){
            return;
        }
        int x = num/26;
        int y = num % 26;
        if (x>26)
            f(x,ans);
        else if(x>0)
            ans += (a[x-1]);
        if(y > 0)
            ans += (a[y-1]);
        return;
    }
    
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        if(columnNumber > 26)
            f(columnNumber, ans);
        else
            ans = a[columnNumber-1];
        return ans;
    }
};