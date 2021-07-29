// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    typedef pair<string,int> pp;
    
    struct compare{
        bool operator()(pp a,pp b){
            if(a.second==b.second) return a.first>b.first;
            else return a.second<b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> umap;
        // calculate freq of each word
        for(string s:words) umap[s]++;
        
        priority_queue<pp,vector<pp>,compare> maxq;
        // push map into max heap
        for(auto itr: umap){
            maxq.push({itr.first,itr.second});
        }
        vector<string> res;
        // push top k frequent strings
        while(k--){
            res.push_back(maxq.top().first);
            maxq.pop();
        }
        return res;
    }
};