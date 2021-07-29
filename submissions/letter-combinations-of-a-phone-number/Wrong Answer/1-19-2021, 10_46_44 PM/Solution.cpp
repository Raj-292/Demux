// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> digitToAlphabet;
    
    void initializeMap() {
        digitToAlphabet.resize(10);
        
        digitToAlphabet[2] = "abc";
        digitToAlphabet[3] = "def";
        digitToAlphabet[4] = "ghi";
        digitToAlphabet[5] = "jkl";
        digitToAlphabet[6] = "mno";
        digitToAlphabet[7] = "pqrs";
        digitToAlphabet[8] = "tuv";
        digitToAlphabet[9] = "wxyz";
    }
    void f(string& digits, int start, string& contri, vector<string>& res) {
        // Base step
        if(start == digits.size()) {
            res.push_back(contri);
            return;
        }
        
        for(int i = 0; i < digitToAlphabet[digits[start]-'0'].size(); i++) {
            contri.push_back(digitToAlphabet[digits[start]-'0'][i]);
            f(digits, start+1, contri, res);
            contri.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string contri;
        
        initializeMap();
        
        f(digits, 0, contri, res);
        
        return res;
    }
};