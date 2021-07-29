// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
  
    static bool cmp(pair<int,int>a , pair<int,int>b)
    {
      if(a.second > b.second) return true;
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
      unordered_map<int,int> mpp;
      int size = nums.size();
      if(size == 1) return nums;
      for(int i = 0; i < size; i++)
        mpp[nums[i]]++;
      
      vector<pair<int,int>> dump;
      for(auto it : mpp)
        dump.push_back(it);
      sort(dump.begin(),dump.end(),cmp);
      vector<int> res;
      
      for(auto itt : dump)
      {
        if(k == 0) break;
        res.push_back(itt.first);
        k--;
      }
      return res;
    }
};