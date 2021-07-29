// https://leetcode.com/problems/sort-characters-by-frequency

// 

// bool compare(char a,char b){
//     if(a==b) return a<b;
//     else return freq[a]>freq[b];
// }

// lambda function-> comparator operator/function/method
// scope, parameters, defination
// [], (), {}

class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for(char c:s) freq[c]++;
        // = -> take up the entire scope
        sort(s.begin(),s.end(),[=](char a,char b){
            if(freq[a]==freq[b]) return a<b;
            else return freq[a]>freq[b];
        });
        return s;
    }
};