// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string,vector<pair<int,string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
           m[key].push_back(make_pair(timestamp,value));
        
    }
    
    string get(string key, int timestamp) {
       vector <pair<int,string>> &v=m[key];
        int lo=0,hi=v.size()-1,mid;
        while(lo<hi)
        {
            mid=lo+(hi-lo+1)/2;
            if(v[mid].first>timestamp)
            {
                hi=mid-1;
            }
            else
            {
              lo=mid;  
            }
        }
        if(v[lo].first<=timestamp)
        {
            return v[lo].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */