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
        f(x,ans);
        ans += (a[y-1]);
        return;
    }
    
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        f(columnNumber, ans);
        return ans;
    }
};