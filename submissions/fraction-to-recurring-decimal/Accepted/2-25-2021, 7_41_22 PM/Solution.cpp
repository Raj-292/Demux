// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
  void populateAfterDecimal(long num,long den , string& res)
  {
      //key: remainder
      //value: index in the res where the remainder occured first time
      unordered_map<long , long> m;
      
      string ans="";
      
      while(num)
      {
          //if num is not found in the map
          if(m.find(num) == m.end())
          {
              m[num] = res.size()-1;
              
              long q = num/den;
              long r = num%den;
              
              res += to_string(q);
              
              if(r==0)
                  return;
              num = r*10;
          }
          else
          {
              ans = res.substr(0 , m[num]+1) + "(" + res.substr(m[num]+1, res.size()-m[num]) + ")";
              res = ans;
              break;
          }
          
      }
      
   
  }
    
    
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) return "0";
        
        string res="";
        
        //negative result
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            res+= "-";
        
        long num = abs(numerator);
        long den = abs(denominator);
        
        //before decimal
        long q = num/den;
        long rem = num%den;
        
        res += to_string(q);
        
        if(rem == 0) 
            return res;
        
        res += ".";
        
        //after the decimal
        
        populateAfterDecimal(rem*10 , den, res);
        
        return res;
    }
};