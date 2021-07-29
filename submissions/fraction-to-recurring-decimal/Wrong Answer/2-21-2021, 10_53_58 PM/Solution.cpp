// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    bool populateAfterDecimal(int num,int den,string &decimal)
    {
        unordered_set <long> s1;
        
        while (num!=0)
        {
            if (s1.count(num)>0)
                return true;
            
            s1.insert(num);
            int q=num/den;
            int rem=num%den;
            
            decimal=decimal+to_string(q);
            num=rem*10;
        }
        
        return false;
    }
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) return "0";
        
        string res = "";
        
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
        bool repeat;
        string decimal={};
        repeat=populateAfterDecimal(rem*10, den,decimal);
        
        if (repeat)
            decimal='('+decimal+')';
        
        return res+decimal;
}
};