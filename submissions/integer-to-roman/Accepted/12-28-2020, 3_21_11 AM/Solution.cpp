// https://leetcode.com/problems/integer-to-roman

class symbolMap {
public:
    symbolMap() {
        m.resize(1001);
        
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";
    }
    string getSymbol(int val) {
        return m[val];
    }
    vector<int> getAllValues() {
        return {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    }
private:
    vector<string> m;
};

class Solution {
public:
    string intToRoman(int num) {
        // create an object of symbolMap
        symbolMap sm;
        string res = "";
        
        vector<int> vals = sm.getAllValues();
    
        // Divide
        for(int i = vals.size()-1; i >= 0; i--) {
            int q = num/vals[i];
            
            while(q) {
                res += sm.getSymbol(vals[i]);
                q--;
            }
            
            num = num%vals[i];
        }
        
        return res;
    }
};