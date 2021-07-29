// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    void populateAfterDecimal(long num, long den, string &res) {
        // Key: Remainder
        // Value: Index in res where the remainder occured for the first time
        unordered_map<long, long> m;
        
        string ans = "";
        while(num) {
            // If num is not found in the map
            if(m.find(num) == m.end()) {
                m[num] = res.size()-1;
                
                long q = num/den;
                long r = num%den;
                
                res += to_string(q);
                
                num = r*10;
            }
            else {
                ans = res.substr(0, m[num]+1) + "(" + res.substr(m[num]+1, res.size()-m[num]) + ")";
                
                res = ans;
                break;
            }
        }
        
    }
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) return "0";
        
        string res = "";
        
        // Negative result
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            res += "-";
        
        long num = abs(numerator);
        long den = abs(denominator);
        
        // Before the decimal
        long q = num/den;
        long rem = num%den;
        
        res += to_string(q);
        
        // Decimal
        if(rem == 0)
            return res;
        
        res += ".";
        
        // After the decimal
        populateAfterDecimal(rem*10, den, res);
        
        return res;
    }
};