// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> digitsToLet;
    void function(){
        digitsToLet.resize(10);
        digitsToLet[2] = "abc";
        digitsToLet[3] = "def";
        digitsToLet[4] = "ghi";
        digitsToLet[5] = "jkl";
        digitsToLet[6] = "mno";
        digitsToLet[7] = "pqrs";
        digitsToLet[8] = "tuv";
        digitsToLet[9] = "wxyz";
    }
    
    void f(string& digits, int start, string& contri, vector<string>& res){
        //base step
        if(start >= digits.size()){
            res.push_back(contri);
            return;
        }
            
        
        //recursive step
        for(int i=0;i<digitsToLet[digits[start]-'0'].size();i++){
            contri.push_back(digitsToLet[digits[start]-'0'][i]);
            f(digits,start+1,contri,res);
            contri.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        function();
        string contri;
        vector<string> res;
        f(digits, 0, contri, res);
        return res;
        
    
        
    }
};