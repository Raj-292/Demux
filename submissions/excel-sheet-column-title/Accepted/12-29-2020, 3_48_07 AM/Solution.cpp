// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        int curr = n, q, r;
        string res = "";
        vector<string> letterToAlphabet = {"Z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y"};
        
        while(curr){
            r = curr%26;
            
            res = letterToAlphabet[r] + res;
            curr = curr/26;
            
            if(r == 0)
                curr--;
        }
        
        return res;
    }
};