// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    //list has iterator to key values
    list<int>l;
    int c;
    unordered_map<int,pair<int,list<int>::iterator>>m;
    
    LRUCache(int capacity) {
       c=capacity;
        
    }
    
    int get(int key) {
      if(m.find(key)==m.end()) 
      {
          return -1;
      }
    //value to be returned
        int res=m[key].first;
        l.erase(m[key].second);
        l.push_front(key);
         m[key].second = l.begin();
        return res;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            l.erase(m[key].second);
            l.push_front(key);
            m[key].second=l.begin();
            m[key].first=value;   
        }
        else
        {
            if(l.size()<c)
            {
                 l.push_front(key);
                 m[key] = make_pair(value, l.begin());    
            }
            else
            {
                int k=l.back();
                l.pop_back();
                m.erase(k);
                l.push_front(key);
               m[key]=make_pair(value,l.begin());
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */