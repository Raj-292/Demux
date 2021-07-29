// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int c;
    
    LRUCache(int capacity) {
        c = capacity;
    }
    
    void update(int key) {
        // Erase
        l.erase(m[key].second);
        
        // Insert at the head
        l.push_front(key);
        
        // Update the reference in the map
        m[key].second = l.begin();
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        
        int res = m[key].first;
        
        // Update this to be the most recent
        update(key);
        
        return res;
    }
    
    void put(int key, int value) {
        // Update
        if (m.find(key) != m.end()) {
            update(key);
            
            // Update the value
            m[key].first = value;
        }
        else {
            if (l.size() == c) {
                // Cache is full
                // Remove the LRU entry
                int k = l.back();
                
                // Remove from the list
                l.pop_back();
                
                // Remove from the map
                m.erase(k);
            }
            // Insert now.
            // Cache is not full
            // Insert at the head of the list
            l.push_front(key);

            // Insert in the map
            m[key] = make_pair(value, l.begin());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */