// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    static string tmp;
    
    static bool compare(char a,char b){
        return tmp.find(a)< tmp.find(b);
    }
    
    string customSortString(string S, string T) {
        tmp = S;
        sort(T.begin(),T.end(),compare);
        return T;
    }
};
string Solution:: tmp;