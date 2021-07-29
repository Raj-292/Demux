// https://leetcode.com/problems/custom-sort-string

// string tmp;

// bool compare(char a,char b){
//     return tmp.find(a)< tmp.find(b); 
// }

// n -> sizeof T
// m -> sizeof S
// worst -> m*nlogn

class Solution {
public:
//     static string tmp;
    
//     static bool compare(char a,char b){
//         return tmp.find(a) < tmp.find(b); 
//     }
    
    string customSortString(string S, string T) {
        // tmp = S;
        sort(T.begin(),T.end(),[=](char a,char b){
            return S.find(a) < S.find(b);
        });
        return T;
    }
};
// string Solution:: tmp;