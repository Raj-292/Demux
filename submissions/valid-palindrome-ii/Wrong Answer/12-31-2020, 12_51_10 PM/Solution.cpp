// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool IsPalindrome(string s, int start, int end){

    while(start<end){
        
        if(s[start]==s[end]){
            start++; end--;
        }
        else
            return false;
    }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        
        while(start<end){
            
            if(s[start]==s[end]){  
                start++; end--;
            }
            else if(IsPalindrome(s, start++, end)){
                return true;
            }
            else if(IsPalindrome(s, start, end--)){
                return true;
            }
            else
                return false;
        }
        return true;
    }
};