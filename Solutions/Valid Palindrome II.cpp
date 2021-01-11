class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start <= end && s[start] == s[end]) {
            start++; end--;
        }

        return (start > end);
    }
    bool validPalindrome(string s) {
        // Find the position of first mismatch
        int n = s.size(), start = 0, end = n - 1;

        while (start <= end && s[start] == s[end]) {
            start++; end--;
        }

        // If no mismatch then already a palindrome
        if (start > end) return true;

        // Otherwise try deleting the start or end
        return (isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1));
    }
};