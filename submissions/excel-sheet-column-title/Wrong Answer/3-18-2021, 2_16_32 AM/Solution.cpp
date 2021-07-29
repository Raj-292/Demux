// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        string a = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        string res = "";
        while(n){
            int t = n%26;
            res = a[t] + res;
            
            n = n/26;
        }
        return res;
    }
};